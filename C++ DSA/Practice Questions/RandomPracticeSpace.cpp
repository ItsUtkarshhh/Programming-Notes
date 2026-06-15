// Intersection of Two Lists
// Problem : There are two lists, which are intersecting at a point in between... and we need to find that point.
// Solution Idea : Analysis : As both the lists are intersecting at a same point, so from that point onwards the list will become one.
//                          : Currently both lists can have different lengths, so traversing each one of them, won't solve the problem.
//                          : What we can do is we can find the length of both the lists and can compare which is shorter or which is longer.. the one which is longer, will move the head of it further until the length from that point becomes same!
//                          : After that, will traverse both of them, and the moment they meet is the intersection point.