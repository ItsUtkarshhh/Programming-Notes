import java.util.Scanner;

public class Start {
    public static void pattern1(int rows) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < rows; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    public static void pattern2(int rows) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    public static void pattern3(int rows) {
        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= i; j++) {
                System.out.print(j);
            }
            System.out.println();
        }
    }

    public static void pattern4(int rows) {
        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= i; j++) {
                System.out.print(i);
            }
            System.out.println();
        }
    }

    public static void pattern5(int rows) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < rows - i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    public static void pattern6(int rows) {
        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= rows - i + 1; j++) {
                System.out.print(j);
            }
            System.out.println();
        }
    }

    public static void pattern7(int rows) {
        for(int i = 0; i < rows; i++) {
            int spaces = rows - i - 1;
            while(spaces > 0) {
                System.out.print("  ");
                spaces--;
            }

            int stars = 2*i + 1;
            while(stars > 0) {
                System.out.print("* ");
                stars--;
            }

            spaces = rows - i - 1;
            while(spaces > 0) {
                System.out.print("  ");
                spaces--;
            }
            System.out.println();
        }
    }

    public static void pattern8(int rows) {        
        for(int i = rows; i > 0; i--) {
            int spaces = rows - i;
            while(spaces > 0) {
                System.out.print("  ");
                spaces--;
            }

            int stars = 2*i - 1;
            while(stars > 0) {
                System.out.print("* ");
                stars--;
            }

            spaces = rows - i;
            while(spaces > 0) {
                System.out.print("  ");
                spaces--;
            }
            System.out.println();
        }
    }

    public static void pattern9(int rows) {
        for(int i = 0; i < rows; i++) {
            int spaces = rows - i - 1;
            while(spaces > 0) {
                System.out.print("  ");
                spaces--;
            }

            int stars = 2*i + 1;
            while(stars > 0) {
                System.out.print("* ");
                stars--;
            }

            spaces = rows - i - 1;
            while(spaces > 0) {
                System.out.print("  ");
                spaces--;
            }
            System.out.println();
        }
        for(int i = rows; i > 0; i--) {
            int spaces = rows - i;
            while(spaces > 0) {
                System.out.print("  ");
                spaces--;
            }

            int stars = 2*i - 1;
            while(stars > 0) {
                System.out.print("* ");
                stars--;
            }

            spaces = rows - i;
            while(spaces > 0) {
                System.out.print("  ");
                spaces--;
            }
            System.out.println();
        }
    }

    public static void pattern10(int rows) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
        for(int i = rows - 1; i > 0; i--) {
            for(int j = i; j > 0; j--) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }

    public static void pattern11(int rows) {
        for(int i = 1; i <= rows; i++) {
            int val = i % 2;
            for(int j = 1; j <= i; j++) {
                System.out.print(val);
                val++;
                val = val % 2;
            }
            System.out.println();
        }
    }

    public static void pattern12(int rows) {
        int cols = rows * 2;
        for(int i = 1; i <= rows; i++) {
            int val = 1;
            while(val <= i) {
                System.out.print(val + " ");
                val++;
            }

            int spaces = cols - 2 * i;
            while(spaces > 0) {
                System.out.print("  ");
                spaces--;
            }

            val = i;
            while(val > 0) {
                System.out.print(val + " ");
                val--;
            }
            System.out.println();
        }
    }

    public static void pattern13(int rows) {
        int count = 1;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j <= i; j++) {
                System.out.print(count++ + " ");
            }
            System.out.println();
        }
    }

    public static void pattern14(int rows) {
        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= i; j++) {
                System.out.print((char)('A' + j - 1) + " ");
            }
            System.out.println();
        }
    }

    public static void pattern15(int rows) {
        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= rows - i + 1; j++) {
                System.out.print((char)('A' + j - 1) + " ");
            }
            System.out.println();
        }
    }

    public static void pattern16(int rows) {
        for(int i = 1; i <= rows; i++) {
            char val = (char)('A' + i - 1);
            for(int j = 1; j <= i; j++) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    public static void pattern17(int rows) {
        for(int i = 0; i < rows; i++) {
            int spaces = rows - i - 1;
            while(spaces > 0) {
                System.out.print("  ");
                spaces--;
            }

            int totalCharLeft = i + 1;
            char val = 'A';
            while(totalCharLeft > 0) {
                System.out.print(val++ + " ");
                totalCharLeft--;
            }

            int totalCharRight = i;
            char val2 = (char)('A' + i - 1);
            while(totalCharRight > 0) {
                System.out.print(val2-- + " ");
                totalCharRight--;
            }

            spaces = rows - i - 1;
            while(spaces > 0) {
                System.out.print("  ");
                spaces--;
            }
            System.out.println();
        }
    }

    public static void pattern18(int rows) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j <= i; j++) {
                System.out.print((char)('A' + rows - j - 1) + " ");
            }
            System.out.println();
        }
    }

    public static void pattern19(int rows) {
        for(int i = 0; i < rows; i++) {
            char val = (char)('A' + rows - 1 - i);
            for(int j = 0; j <= i; j++) {
                System.out.print(val++ + " ");
            }
            System.out.println();
        }
    }

    public static void pattern20(int rows) {
        for(int i = 0; i < rows; i++) {
            int stars = rows - i;
            while(stars > 0) {
                System.out.print("* ");
                stars--;
            }

            int spaces = 2*i;
            while(spaces > 0) {
                System.out.print("  ");
                spaces--;
            }

            stars = rows - i;
            while(stars > 0) {
                System.out.print("* ");
                stars--;
            }
            System.out.println();
        }
        for(int i = 0; i < rows; i++) {
            int stars = i + 1;
            while(stars > 0) {
                System.out.print("* ");
                stars--;
            }

            int spaces = 2*rows - 2*(i+1);
            while(spaces > 0) {
                System.out.print("  ");
                spaces--;
            }

            stars = i + 1;
            while(stars > 0) {
                System.out.print("* ");
                stars--;
            }
            System.out.println();
        }
    }

    public static void pattern21(int rows) {
        for(int i = 0; i < rows; i++) {
            int stars = i + 1;
            while(stars > 0) {
                System.out.print("* ");
                stars--;
            }

            int spaces = (2*rows) - (2*(i+1));
            while(spaces > 0) {
                System.out.print("  ");
                spaces--;
            }

            stars = i + 1;
            while(stars > 0) {
                System.out.print("* ");
                stars--;
            }
            System.out.println();
        }
        for(int i = 0; i < rows; i++) {
            int stars = rows - (i+1);
            while(stars > 0) {
                System.out.print("* ");
                stars--;
            }

            int spaces = 2*(i+1);
            while(spaces > 0) {
                System.out.print("  ");
                spaces--;
            }

            stars = rows - (i+1);
            while(stars > 0) {
                System.out.print("* ");
                stars--;
            }
            System.out.println();
        }
    }

    public static void pattern22(int rows) {
        for(int i = 0; i < rows; i++) {
            if(i == 0 || i == (rows - 1)) {
                int stars  = rows;
                while(stars > 0) {
                    System.out.print("* ");
                    stars--;
                }
            }
            else {
                System.out.print("* ");
                
                int spaces = rows - 2;
                while(spaces > 0) {
                    System.out.print("  ");
                    spaces--;
                }

                System.out.print("* ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter your rows : ");
        int rows = sc.nextInt();

        System.out.println("Pattern : ");
        // pattern1(rows);
        // pattern2(rows);
        // pattern3(rows);
        // pattern4(rows);
        // pattern5(rows);
        // pattern6(rows);
        // pattern7(rows);
        // pattern8(rows);
        // pattern9(rows);
        // pattern10(rows);
        // pattern11(rows);
        // pattern12(rows);
        // pattern13(rows);
        // pattern14(rows);
        // pattern15(rows);
        // pattern16(rows);
        // pattern17(rows);
        // pattern18(rows);
        // pattern19(rows);
        // pattern20(rows);
        // pattern21(rows);
        pattern22(rows);

        sc.close();
    }
}
