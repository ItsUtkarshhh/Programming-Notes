import java.util.Scanner;
import java.util.Arrays;

public class Practice {
    // Q1 : Count all Digits of a Number
    public static int countDigits(int num) {
        int count = 0;
        while(num != 0) {
            num /= 10;
            count++;
        }
        return count;
    }

    // Q2 : Count number of odd digits in a number
    public static int countOddDigits(int num) {
        int count = 0;
        while(num != 0) {
            int digit = num % 10;
            num = num/10;
            if(digit % 2 != 0) count++;
        }
        return count;
    }

    // Q3 : Reverse a number
    public static int reverseNum(int num) {
        int val = num;
        int ans = 0;
        while(val != 0) {
            int digit = val % 10;
            ans = (ans * 10) + digit;
            val = val / 10;
        }
        return ans;
    }

    // Q4 : Palindrome Number
    public static boolean palindromeNumber(int num) {
        int val = num;
        int reversedNum = reverseNum(val);
        return reversedNum == val;
    }

    // Q5 : Return the Largest Digit in a Number
    public static int largestDigit(long num) {
        long val = Math.abs(num);
        int maxi = 0;
        while(val != 0) {
            int digit = (int)val % 10;
            if(digit > maxi) maxi = digit;
            val = val / 10;
        }
        return maxi;
    }

    // Q6 : Factorial of a given number
    public static long factorial(long num) {
        long ans = num; 
        for(long i = num - 1; i >= 1; i--) {
            ans *= i;
        }
        return ans;
    }

    // Q7 : Check if the Number is Armstrong
    public static boolean checkArmstrong(int num) {
        int val = num;
        int count = countDigits(num);
        int sum = 0;
        while(val != 0) {
            int digit = val % 10;
            sum += Math.round(Math.pow(digit, count));
            val = val / 10;
        }
        return num == sum;
    }

    // Q8 : Check if the Number is Perfect (whose proper divisors (excluding the number itself) add up to the number itself)
    public static boolean perfectNum(int num) {
        int val = num;
        int sum = 1;
        for(int i = 2; i <= Math.sqrt(val); i++) {
            if(val % i == 0) {
                sum += i;
                if(i != val / i) {
                    sum += val / i;
                }
            }
        }
        return sum == val;
    }

    // Q9 : Check if the number is prime or not
    public static boolean isPrime(int num) {
        int val = num;
        if (num < 2) return false;
        for(int i = 2; i < val; i++) {
            if(val % i == 0) return false;
        }
        return true;
    }

    public static boolean isPrime2(int num) {
        int val = num;
        if (num < 2) return false;
        for(int i = 2; i <= Math.sqrt(val); i++) {
            if(val % i == 0) return false;
        }
        return true;
    }

    // Q10 :  Count of Prime Numbers till N
    public static void isPrime3(int num) {
        boolean[] sieve = new boolean[num + 1];
        Arrays.fill(sieve, true);

        sieve[0] = false;
        sieve[1] = false;

        for(int i = 2; i < Math.sqrt(num); i++) {
            if(sieve[i]) {
                for(int j = i*i; j <= num; j = j + i) {
                    sieve[j] = false;
                }
            }
        }

        System.out.print("All Prime numbers : ");
        for(int i = 0; i < sieve.length; i++) {
            if(sieve[i]) System.out.print(i + " ");
        }
    }

    // Q11 : GCD of Two Numbers
    public static int GCD(int num1, int num2) {
        int mini = Math.min(num1, num2);
        int gcdVal = 1;
        for(int i = 2; i <= mini; i++) {
            if(num1 % i == 0 && num2 % i == 0) {
                gcdVal = i;
            }
        }
        return gcdVal;
    }

    public static int GCD2(int num1, int num2) {
        while(num2 != 0) {
            int rem = num1 % num2;
            num1 = num2;
            num2 = rem;
        }
        return num1;
    }

    // Q12 : LCM of two numbers
    public static int LCM(int num1, int num2) { // Unsafe due to while(true) & memory limit
        int val = Math.max(num1, num2);
        int lcmVal = -1;
        while(true) {
            if(val % num1 == 0 && val % num2 == 0) {
                lcmVal = val;
                break;
            }
        }
        return lcmVal;
    }

    public static int LCM2(int num1, int num2) {
        int val = Math.max(num1, num2);
        int maxLimit = num1 * num2;
        int lcmVal = -1;
        for(int i = val; i <= maxLimit; i++) {
            if(i % num1 == 0 && i % num2 == 0) {
                lcmVal = i;
                break;
            }
        }
        return lcmVal;
    }

    public static int LCM3(int num1, int num2) { // LCM(a, b) = (a*b)/GCD(a, b)
        if(num1 < 1 || num2 < 1) return -1;
        return (num1 / GCD2(num1, num2)) * num2;
    }

    // Q13 : Divisors of a Number
    public static void divisorsOfNum(int num) {
        for(int i = 1; i <= Math.sqrt(num); i++) {
            if(num % i == 0) {
                System.out.print(i + " ");
                if(i != num/i) {
                    System.out.print((num/i) + " ");
                }
            }
        }
        System.out.println();
    }

    public static void divisorsOfNumSorted(int num) {
        for(int i = 1; i <= Math.sqrt(num); i++) {
            if(num % i == 0) {
                System.out.print(i + " ");
            }
        }
        for(int i = (int)Math.sqrt(num); i >= 1; i--) {
            if(num % i == 0) {
                if(i != num / i) {
                    System.out.print((num/i) + " ");
                }
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // A1
        // System.out.print("Enter the number : ");
        // int num = sc.nextInt();
        // System.out.print("Total digits : " + countDigits(num));

        // A2
        // System.out.print("Enter the number : ");
        // int num = sc.nextInt();
        // System.out.print("Total odd digits : " + countOddDigits(num));

        // A3
        // System.out.print("Enter the number : ");
        // int num = sc.nextInt();
        // System.out.print("Reversed : " + reverseNum(num));

        // A4
        // System.out.print("Enter the number : ");
        // int num = sc.nextInt();
        // System.out.print("Palindrome? : " + palindromeNumber(num));

        // A5
        // System.out.print("Enter the number : ");
        // long num = sc.nextLong();
        // System.out.print("Largest Digit in " + num + " : " + largestDigit(num));

        // A6
        // System.out.print("Enter the number : ");
        // long num = sc.nextLong();
        // System.out.print("Factorial of " + num + " : " + factorial(num));

        // A7
        // System.out.print("Enter the number : ");
        // int num = sc.nextInt();
        // System.out.print("Armstrong? : " + checkArmstrong(num));

        // A8
        // System.out.print("Enter the number : ");
        // int num = sc.nextInt();
        // System.out.print("Perfect Number? : " + perfectNum(num));

        // A9
        // System.out.print("Enter the number : ");
        // int num = sc.nextInt();
        // System.out.println("Prime Number? : " + isPrime(num));
        // System.out.println("Prime Number? : " + isPrime2(num));
        
        // A10
        // System.out.print("Enter the number : ");
        // int num = sc.nextInt();
        // isPrime3(num);

        // A11
        // System.out.print("Enter the numbers : ");
        // int num1 = sc.nextInt();
        // int num2 = sc.nextInt();
        // System.out.printf("GCD of %d & %d is : %d\n", num1, num2, GCD(num1, num2));
        // System.out.printf("GCD of %d & %d is : %d\n", num1, num2, GCD2(num1, num2));

        // A12
        // System.out.print("Enter the numbers : ");
        // int num1 = sc.nextInt();
        // int num2 = sc.nextInt();
        // System.out.printf("GCD of %d & %d is : %d\n", num1, num2, LCM(num1, num2));
        // System.out.printf("GCD of %d & %d is : %d\n", num1, num2, LCM2(num1, num2));
        // System.out.printf("GCD of %d & %d is : %d\n", num1, num2, LCM3(num1, num2));
        
        // A13
        // System.out.print("Enter the numbers : ");
        // int num = sc.nextInt();
        // divisorsOfNum(num);
        // divisorsOfNumSorted(num);

        sc.close();
    }
}
