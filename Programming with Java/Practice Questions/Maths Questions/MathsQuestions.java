// ------------------------------------------------------- Maths Based Questions --------------------------------------------------------->
// Question 1 : Print the first n Fibonacci numbers!
import java.util.*;

class Question1 {
    public static void printFib(int n) {
        if(n <= 0) {
            System.out.print("Invalid Input!");
            return;
        }
        int i = 0;
        int first = 0;
        int second = 1;
        while(i <= n) {
            System.out.print(first + " ");
            int next = first + second;
            first = second;
            second = next;
            i++;
        }
    }
    
    public static void main(String[] args) {
        System.out.print("Enter n : ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        printFib(n);
    }
}

// Question 2 : Find the nth Fibonacci number!
class Question2 {
    public static void nthFib(int n) {
        if(n <= 0) {
            System.out.print("Invalid Input!");
            return;
        }
        int i = 1;
        int first = 0;
        int second = 1;
        while(i <= n) {
            int next = first + second;
            first = second;
            second = next;
            i++;
        }
        System.out.print(first);
    }
    
    public static void main(String[] args) {
        System.out.print("Enter n : ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        nthFib(n);
    }
}

// Question 3 : Sum of the first n fibonacci numbers!
class Question3 {
    public static void sumOfFib(int n) {
        if(n <= 0) {
            System.out.print("Invalid Input!");
            return;
        }
        int sum = 0;
        int i = 1;
        int first = 0;
        int second = 1;
        while(i <= n) {
            sum += first;
            int next = first + second;
            first = second;
            second = next;
            i++;
        }
        System.out.print(sum);
    }

    public static void main(String[] args) {
        System.out.print("Enter n : ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        sumOfFib(n);
    }
}

// Question 4 : Check if a given number is a Fibonacci number!
class Question4 {
    public static boolean IsPerfectSquare(double n) {
        double x = Math.sqrt(n);
        return (x * x) == n;
    }
    
    public static boolean checkFib(int n) {
        double expr1 = (5 * n * n) + 4;
        double expr2 = (5 * n * n) - 4;
        return IsPerfectSquare(expr1) || IsPerfectSquare(expr2);
    }
    
    public static void main(String[] args) {
        System.out.print("Enter n : ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        if(checkFib(n)) {
            System.out.println("Yes!");
        }
        else {
            System.out.print("No");
        }
    }
}

// Question 5 : Last digit of the nth Fibonacci number!
class Question5 {
    public static void lastDigitOfNthFib(int n) {
        if(n <= 0) {
            System.out.print("Invalid Input!");
            return;
        }
        int i = 1;
        int first = 0;
        int second = 1;
        while(i <= n) {
            int next = first + second;
            first = second;
            second = next;
            i++;
        }
        System.out.print(first % 10);
    }
    
    public static void main(String[] args) {
        System.out.print("Enter n : ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        lastDigitOfNthFib(n);
    }
}

// Question 6 : Print Fibonacci till N <= 5.
class Question6 {
    public static void FibTillN(int n) {
        if(n <= 0) {
            System.out.print("Invalid Input!");
            return;
        }
        int first = 0;
        int second = 1;
        while(first <= n) {
            System.out.print(first + " ");
            int next = first + second;
            first = second;
            second = next;
        }
    }

    public static void main(String[] args) {
        System.out.print("Enter n : ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        FibTillN(n);
    }
}

// Question 7 : Print first n terms of fibonacci series in reverse!
class Question7 {
    public static void printFibReverse(int n) {
        if(n <= 0) {
            System.out.print("Invalid Input!");
            return;
        }
        
        ArrayList<Integer> fibList = new ArrayList<>();
        int first = 0;
        int second = 1;
        
        while(first <= n) {
            fibList.add(first);
            int next = first + second;
            first = second;
            second = next;
        }
        
        for(int i = fibList.size() - 1; i >= 0; i--) {
            System.out.print(fibList.get(i) + " ");
        }
    }
    
    public static void main(String[] args) {
        System.out.print("Enter n : ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        printFibReverse(n);
    }
}

// Question 8 : Print all even Fibonacci numbers among the first n terms
//            : Print all even Fibonacci numbers less than or equal to n
class Question8 {
    public static void printEvenFib1(int n) {
        if(n <= 0) {
            System.out.print("Invalid Input!");
            return;
        }
        
        int i = 1;
        int first = 0;
        int second = 1;
        
        while(i <= n) {
            if(first % 2 == 0) {
                System.out.print(first + " ");
            }
            int next = first + second;
            first = second;
            second = next;
            i++;
        }
    }
    
    public static void printEvenFib2(int n) {
        if(n <= 0) {
            System.out.print("Invalid Input!");
            return;
        }

        int first = 0;
        int second = 1;
        
        while(first <= n) {
            if(first % 2 == 0) {
                System.out.print(first + " ");
            }
            int next = first + second;
            first = second;
            second = next;
        }
    }

    public static void main(String[] args) {
        System.out.print("Enter n : ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        printEvenFib1(n);
        System.out.println();
        printEvenFib2(n);
    }
}

// Question 9 : Find the first Fibonacci number with exactly k digits among the first n terms.
class Question9 {
    public static int numOfDigits(int k) {
        if(k == 0) return 0;
        int count = 0;
        while(k != 0) {
            count++;
            k /= 10;
        }
        return count;
    }

    public static int numOfDigits2(int k) {
        if(k == 0) return 0;
        return (int)Math.log10(k) + 1;
    }

    public static void FibNumKDigits(int n, int k) {
        if(n <= 0) {
            System.out.print("Invalid Input!");
            return;
        }
        
        int i = 1;
        int first = 0;
        int second = 1;
        
        while(i <= n) {
            if(numOfDigits(first) == k) {
                System.out.print(first);
                return;
            }
            int next = first + second;
            first = second;
            second = next;
            i++;
        }
    }
    
    public static void main(String[] args) {
        System.out.print("Enter n : ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        System.out.print("Enter number of digits : ");
        int k = sc.nextInt();
        
        FibNumKDigits(n, k);
    }
}

// Question 10 : Find how many Fibonacci numbers lie between a and b
class Question10 {
    public static void FibNumBeteweenAB(int a, int b) {
        if(a > b || b <= 0) {
            System.out.println("Invalid Input");
            return;
        }
        int first = 0;
        int second = 1;
        while(first <= b) {
            if(first >= a) {
                System.out.print(first + " ");
            }
            int next = first + second;
            first = second;
            second = next;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter a : ");
        int a = sc.nextInt();
        
        System.out.print("Enter b : ");
        int b = sc.nextInt();
        
        FibNumBeteweenAB(a, b);
    }
}

// Question 11 : Find Greatest Common Divisor (GCD)/ Highest Common Factor (HCF) of two numbers!
class Question11 {
    public static void GCD1(int a, int b) {
        int val = Math.min(a, b);
        while(val >= 0) {
            if(a % val == 0 && b % val == 0) {
                System.out.println(val);
                return;
            }
            val--;
        }
    }

    public static void GCD2(int divisor, int dividend) {
        while(divisor != 0) {
            int temp  = divisor;
            divisor = dividend % divisor;
            dividend = temp;
        }
        System.err.println(dividend);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter a : ");
        int a = sc.nextInt();
        
        System.out.print("Enter b : ");
        int b = sc.nextInt();
        
        GCD1(a, b);
        GCD2(a, b);
    }
}

// Question 12 : Find Least Common Multiple (LCM) of two numbers!
class Question12 {
    public static void LCM(int a, int b) {
        int val = Math.max(a, b);
        while(true) {
            if(val % a == 0 && val % b == 0) {
                System.out.println(val);
                return;
            }
            val++;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter a : ");
        int a = sc.nextInt();
        
        System.out.print("Enter b : ");
        int b = sc.nextInt();
        
        LCM(a, b);
    }
}