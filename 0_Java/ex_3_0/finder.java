import java.util.*;

class finder
{
    static int ft_brute_force(int[] arr, int num)
    {
        for (int i = 0; i < arr.length; i++)
        {
            if (arr[i] == num)
                return (i);
        }
        return (-1);
    }

    static int ft_binary_search(int[] arr, int num, int st, int end)
    {
        int n;

        n = (st + end) / 2;

        if (arr[n] == num)
            return (n);
        else if (arr[n] > num)
            return (ft_binary_search(arr, num, st, n - 1));
        else
            return (ft_binary_search(arr, num, n + 1, end));
    }

    static int[] ft_generate_arr(int len)
    {
        int[] arr = new int[len];
        for (int i = 0; i < len; i++)
        {
            arr[i] = (int)(Math.random() * 1000000);
        }
        return (arr);
    }


    public static void main(String[] args)
    {
        int[] arr = ft_generate_arr(100000000);

        Arrays.sort(arr);

        long time_s = System.currentTimeMillis();
        ft_brute_force(arr, 2223);
        long time_e = System.currentTimeMillis();
        System.out.println("brute_force time = " + (time_e - time_s));

        time_s = System.currentTimeMillis();
        ft_binary_search(arr, 2223, 0, arr.length);
        time_e = System.currentTimeMillis();
        System.out.println("binery search time = " + (time_e - time_s));
    }
}