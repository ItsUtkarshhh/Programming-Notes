import java.util.HashMap;
import java.util.Scanner;

public class Main {
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

        int maxEle = -1;
        int maxValue = Integer.MIN_VALUE;
        
        int secMaxEle = maxEle;
        int secMaxValue = maxValue;

        for(HashMap.Entry<Integer, Integer> entry : hash.entrySet()) {
            if(entry.getValue() > maxValue) {
                secMaxEle = maxEle;
                secMaxValue = maxValue;
                
                maxEle = entry.getKey();
                maxValue = entry.getValue();
            }
            else if
                (entry.getValue() < maxValue &&
                (entry.getValue() > secMaxValue ||
                (entry.getValue() == secMaxValue && entry.getKey() < secMaxEle
                ))) 
            {
                secMaxEle = entry.getKey();
                secMaxValue = entry.getValue();
            }
        }
        return secMaxEle;
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
