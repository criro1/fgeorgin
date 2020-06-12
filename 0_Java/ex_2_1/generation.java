import java.util.*;

class generation
{
    int[] nums;
    int[] weight;

    public generation(int[] nums, int[] weight)
    {
        this.nums = nums;
        this.weight = weight;
    }

    public static int ft_sum_w(int[] weight)
    {
        int res;

        res = 0;
        for (int i = 0; i < weight.length; i++)
            res += weight[i];
        return (res);
    }

    public int ft_solution(int[] nums_new)
    {
        int n;

        n = 0;
        for (int i = 0; i < nums.length; i++)
        {
            for (int j = 0; j < weight[i]; j++)
            {
                nums_new[n] = nums[i];
                n++;
            }
        }
        System.out.println("Nums' array:");
        for (int i = 0; i < nums.length; i++)
        {
            System.out.print(nums[i] + " ");
        }
        System.out.println();
        System.out.println("Weights' array:");
        for (int i = 0; i < weight.length; i++)
        {
            System.out.print(weight[i] + " ");
        }
        System.out.println();
        System.out.println("New nums' array:");
        for (int i = 0; i < nums_new.length; i++)
        {
            System.out.print(nums_new[i] + " ");
        }
        System.out.println();
        return (nums_new[(int)((Math.random() * nums_new.length))]);
    }

    public static void main(String[] args)
    {
        int[] arr = new int[(int)(Math.random() * 5) + 1];
        int[] weight = new int[arr.length];

        for (int i = 0; i < arr.length; i++) 
        {
            arr[i] = (int)(Math.random() * 11);
            weight[i] = (int)(Math.random() * 10) + 1;
        }
        generation rand = new generation(arr, weight);
        int[] nums = new int[ft_sum_w(weight)];
        System.out.println("Number = " + rand.ft_solution(nums));
    }
}