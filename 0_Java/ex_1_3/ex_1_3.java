import java.util.*;

class ex_1_3
{
    public static int[] ft_remove_el(int[] arr, int num)
    {
        int i;
        int r;

        i = 0;
        r = 0;
        while (i < arr.length)
        {
            if (arr[i] == num)
            {
                arr[i - r] = arr[i + 1];
                r++;
            }
            i++;
        }
        return (Arrays.copyOf(arr, arr.length - r));
    }

    public static void main(String[] args)
    {
        int[] arr = new int[(int)(Math.random() * 100)];

        for (int i = 0; i < arr.length; i++)
        {
            arr[i] = (int)(Math.random() * 100);
        }
        
        System.out.println("What number do you want to remove?");
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        arr = ft_remove_el(arr, num);
        
        for (int i = 0; i < arr.length; i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}