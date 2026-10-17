// Garbage Collection & Object Lifecycle
// Garbage Collection (GC) is the JVM's automatic memory management process that frees developers from manual memory deallocation (free() or delete in C/C++).
// The 7-Stage Object Lifecycle : An object transitions through specific lifecycle states from allocation to memory release
//                              : Created : Memory is allocated on the Heap, constructors run, and field initializations execute
//                              : In Use (Strongly Reachable) : Held by at least one live reference in a running thread's stack frame or a static context
//                              : Invisible : Out of scope for current execution block, but the reference frame might briefly remain active in execution (e.g., intermediate compiler optimizations)
//                              : Unreachable : No active references point to the object—it is now eligible for Garbage Collection
//                              : Collected : The JVM's GC algorithm marks the object and identifies it for destruction
//                              : Finalized : If the object overrides cleanup methods, JVM queues it for finalization before memory release
//                              : Deallocated : Physical memory on the Heap is reclaimed.

// When Does an Object Become Eligible for GC?
// An object is eligible for GC when it is unreachable from any GC Root.
// GC Roots include : Local variables living in active thread stack frames
//                  : Static variables in loaded class definitions
//                  : Active Java thread objects
//                  : JNI (Java Native Interface) global/local references

// Generational Garbage Collection: Young vs. Old Generation
// Generational Garbage Collection is built on an empirical observation called the Weak Generational Hypothesis : most objects created in an application become unreachable (die) very quickly after their creation (e.g., local method variables, temporary loop objects, HTTP request/response payloads).
// Rather than scanning the entire Heap every time memory needs reclaiming (which would cause massive execution pauses), the JVM divides Heap memory into distinct regions based on the age of objects.
// Breakdown of the Heap Regions : Young Generation
//                               : Old Generation
// Young Generation : The Young Generation is where fresh allocations occur. It is optimized for high-throughput, low-latency collection because 90%+ of these objects will not survive their first GC cycle. It is split into three parts
//                  : Eden Spaces : The entry point. Every time you write new MyObject(), the memory is allocated inside Eden
//                  : Survivor Spaces (S0 & S1 / From & To) : Two equally-sized spaces (Survivor 0 and Survivor 1). At any given moment, one survivor space is active (holding objects) while the other is completely empty. 
// Old Generation (Tenured) : Contains objects that have survived multiple rounds of Garbage Collection in the Young Generation. These are long-lived components like Spring Beans, Singletons, DB Connection Pools, and global application state caches.

// End-to-End Lifecycle : Allocation in Eden : When your application executes new Order(), memory is allocated in the Eden Space.
//                      : Triggering Minor GC : When Eden becomes completely full, the JVM triggers a Minor GC. Application execution experiences a brief "Stop-The-World" (STW) pause while the collector scans only the Young Generation
//                      : Copying to Survivor Space : Unreachable objects in Eden are reclaimed immediately
//                                                  : Live (reachable) objects are copied to the empty Survivor Space (e.g., S0)
//                                                  : Their internal Age Counter (Tenuring Threshold) is set to 1
//                                                  : Eden is completely cleared
//                      : Ping-Ponging Between S0 and S1 : On the next Minor GC : Surviving objects from Eden AND S0 are copied over to S1
//                                                                              : The age counter for surviving objects increments by 1
//                                                                              : Eden and S0 are wiped clean
//                                                                              : Roles swap: S1 is now the active "From" space, and S0 becomes the empty "To" target for the next cycle
//                      : Tenuring (Promotion) to Old Generation : When an object survives enough Minor GC cycles to reach the MaxTenuringThreshold (JVM default is typically 15, configured via -XX:MaxTenuringThreshold), it is promoted to the Old Generation
//                      : Triggering Major / Full GC : When the Old Generation fills up, the JVM executes a Major GC (or Full GC). This scans the Old Generation (and optionally Metaspace) to clear dead long-lived objects