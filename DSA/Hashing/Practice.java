package DSA.Hashing;

import java.util.Scanner;
import java.util.HashMap;

public class Practice {
    // Q1 : Highest Occurring Element in an Array
    public static int maxFreq(int[] arr) {
        if(arr == null || arr.length == 0) {
            return -1;
        }

        HashMap<Integer, Integer> hash = new HashMap<>();
        for(int num : arr) {
            hash.put(num, hash.getOrDefault(num, 0) + 1);
        }

        int maxValue = 0;
        int maxElement = arr[0];

        for(HashMap.Entry<Integer, Integer> entry : hash.entrySet()) {
            if(entry.getValue() > maxValue) {
                maxElement = entry.getKey();
                maxValue = entry.getValue();
            }
        }

        return maxElement;
    }

    // Q2 : Second Highest Occurring Element
    public static int secondHighestFreq(int[] arr) {
        if(arr == null || arr.length == 0) {
            return -1;
        }

        HashMap<Integer, Integer> hash = new HashMap<>();
        for(int num : arr) {
            hash.put(num, hash.getOrDefault(num, 0) + 1);
        }

        int maxElement = -1;    
        int maxElementFreq = 0;

        int secondMaxElement = -1;
        int secondMaxElementFreq = 0;

        for(HashMap.Entry<Integer, Integer> entry : hash.entrySet()) {
            int currentElement = entry.getKey();
            int currentElementFreq = entry.getValue();

            if(currentElementFreq > maxElementFreq) {
                secondMaxElement = maxElement;
                secondMaxElementFreq = maxElementFreq;

                maxElement = currentElement;
                maxElementFreq = currentElementFreq;
            }
            else if(currentElementFreq < maxElementFreq &&
                (currentElementFreq > secondMaxElementFreq ||
                    (currentElementFreq == secondMaxElementFreq && currentElement < secondMaxElement)
                )
            ) {
                secondMaxElement = currentElement;
                secondMaxElementFreq = currentElementFreq;
            }
        }
        return secondMaxElement;
    }

    // Q3 : Sum of Highest & Lowest Frequencies

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
        // System.out.printf("Maximum occuring value : %d", maxFreq(arr));

        // A2
        System.out.print("Enter array size : ");
        int size = sc.nextInt();
        System.out.print("Enter you array elements : ");
        int[] arr = new int[size];
        for(int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.printf("Second Maximum occuring value : %d", secondHighestFreq(arr));

        sc.close();
    }   
}
