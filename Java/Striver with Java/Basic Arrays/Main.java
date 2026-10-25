import java.util.Scanner;

public class Main {
    // Q1 : Sum of arrays elements
    public static int arraySum(int[] arr) {
        int sum = 0;
        for(int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        return sum;
    }

    // Q2 : Count of odd numbers in Array
    public static int countOdd(int[] arr) {
        int count = 0;
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] % 2 != 0) count++;
        }
        return count;
    }

    // Q3 : Check if the Array is Sorted I
    public static boolean checkSorted(int[] arr) {
        for(int i = 0; i < arr.length - 1; i++) {
            if(arr[i] > arr[i + 1]) return false;
        }
        return true;
    }

    // Q4 : Reverse an array
    public static int[] reverseArray(int[] arr) {
        int temp = 0;
        int start = 0; int end = arr.length - 1;
        while(start <= end) {
            temp = arr[end];
            arr[end] = arr[start];
            arr[start] = temp;
            start++; end--;
        }
        return arr;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // A1
        // System.out.print("Enter array size : ");
        // int size = sc.nextInt();
        // System.out.print("Enter you array elements : ");
        // int[] arr = new int[size];
        // for(int i = 0; i < size; i++) {
        //     arr[i] = sc.nextInt();
        // }
        // System.out.printf("Sum of array elements : %d", arraySum(arr));

        // A2
        // System.out.print("Enter array size : ");
        // int size = sc.nextInt();
        // System.out.print("Enter you array elements : ");
        // int[] arr = new int[size];
        // for(int i = 0; i < size; i++) {
        //     arr[i] = sc.nextInt();
        // }
        // System.out.printf("Odd count : %d", countOdd(arr));

        // A3 
        // System.out.print("Enter array size : ");
        // int size = sc.nextInt();
        // System.out.print("Enter you array elements : ");
        // int[] arr = new int[size];
        // for(int i = 0; i < size; i++) {
        //     arr[i] = sc.nextInt();
        // }
        // System.out.printf("Array is sorted? : %b", checkSorted(arr));

        // A4
        System.out.print("Enter array size : ");
        int size = sc.nextInt();
        System.out.print("Enter you array elements : ");
        int[] arr = new int[size];
        for(int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }
        int[] result = reverseArray(arr);
        for(int num : result) {
            System.out.print(num + " ");
        }
        System.out.println();
        for(int num : arr) {
            System.out.print(num + " ");
        }

        sc.close();
    }
}
