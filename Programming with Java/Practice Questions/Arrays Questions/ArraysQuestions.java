// ------------------------------------------------------- Arrays Based Questions --------------------------------------------------------->
// Question 1 : Print all elements of an array
import java.util.*;

class Question1 {
    public static void printArray1(int[] arr) {
        for(int num : arr) {
            System.out.print(num + " ");
        }
    }
    
    public static void printArray2(ArrayList<Integer> arr) {
        for(int num : arr) {
            System.out.print(num + " ");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Using normal arrays!
        System.out.print("Enter size : ");
        int size1 = sc.nextInt();
        
        System.out.print("Enter the array elements : ");
        int[] arr1 = new int[size1];
        for(int i = 0; i < size1; i++) {
            arr1[i] = sc.nextInt();
        }
        System.out.print("Arr1 : ");
        printArray1(arr1);
        
        // Using ArrayList!
        System.out.print("Enter size2 : ");
        int size2 = sc.nextInt();
    
        System.out.print("Enter the array elements : ");
        ArrayList<Integer> arr2 = new ArrayList<>();
        for(int i = 0; i < size2; i++) {
            int num = sc.nextInt();
            arr2.add(num);
        }
        System.out.print("Arr2 : ");
        printArray2(arr2);
    }
}

// Question 2 : Find the index of a given element!
class Question2 {
    public static void findIndex1(int[] arr, int key) {
        boolean found = false;
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] == key) {
                found = true;
                System.out.printf("Key found at %d", i);
                return;
            }
        }
        if(!found) {
            System.out.print("Key not found!");
            return;
        }
    }
    
    public static void findIndex2(ArrayList<Integer> arr, int key) {
        boolean found = false;
        for(int i = 0; i < arr.size(); i++) {
            if(arr.get(i) == key) {
                found = true;
                System.out.printf("Key found at %d", i);
                return;
            }
        }
        if(!found) {
            System.out.print("Key not found!");
            return;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Using normal arrays!
        System.out.print("Enter size1 : ");
        int size1 = sc.nextInt();
        
        System.out.print("Enter array1 : ");
        int[] arr1 = new int[size1];
        for(int i = 0; i < size1; i++) {
            arr1[i] = sc.nextInt();
        }
        
        
        // Using ArrayList!
        System.out.print("Enter size2 : ");
        int size2 = sc.nextInt();
        
        System.out.print("Enter array2 : ");
        ArrayList arr2 = new ArrayList<>();
        for(int i = 0; i < size2; i++) {
            int num = sc.nextInt();
            arr2.add(num);
        }
        
        System.out.print("Enter Key : ");
        int key = sc.nextInt();
        findIndex1(arr1, key);
        System.out.println();
        findIndex2(arr2, key);
    }
}

// Question 3 : Find the max & min in the given array!
class Question3 {
    public static int maxi(ArrayList<Integer> arr) {
        int maxVal = Integer.MIN_VALUE;
        for(int i = 0; i < arr.size(); i++) {
            if(arr.get(i) >= maxVal) {
                maxVal = arr.get(i);
            }
        }
        return maxVal;
    }

    public static int mini(ArrayList<Integer> arr) {
        int minVal = Integer.MAX_VALUE;
        for(int i = 0; i < arr.size(); i++) {
            if(arr.get(i) <= minVal) {
                minVal = arr.get(i);
            }
        }
        return minVal;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the size : ");
        int size = sc.nextInt();

        ArrayList<Integer> arr = new ArrayList<>();
        for(int i = 0; i < size; i++) {
            int num = sc.nextInt();
            arr.add(num);
        }

        System.out.println("Max : " + maxi(arr));
        System.out.println("Min : " + maxi(arr));
    }
}

// Question 4 : Count occurence/frequency of each element!
class Question4 {
    public static int maxi(ArrayList<Integer> arr) {
        int maxVal = Integer.MIN_VALUE;
        for(int i = 0; i < arr.size(); i++) {
            if(arr.get(i) >= maxVal) {
                maxVal = arr.get(i);
            }
        }
        return maxVal;
    }

    public static void countFreq(ArrayList<Integer> arr) {
        int maxElement = maxi(arr);
        int[] freq = new int[maxElement + 1];

        for(int i = 0; i < arr.size(); i++) {
            freq[arr.get(i)]++;
        }

        for(int i = 0; i < maxElement + 1; i++) {
            if(freq[i] != 0) {
                System.out.printf("Frequency of %d is %d", i, freq[i]);
                System.out.println();
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the size : ");
        int size = sc.nextInt();

        ArrayList<Integer> arr = new ArrayList<>();
        for(int i = 0; i < size; i++) {
            int num = sc.nextInt();
            arr.add(num);
        }

        countFreq(arr);
    }
}