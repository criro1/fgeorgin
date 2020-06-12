class ex_1_0
{
    public static double ft_max(double[] arr)
    {
        double max;

        max = arr[0];
        for (int i = 1; i < arr.length; i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }
        return (max);
    }

    public static double ft_min(double[] arr)
    {
        double min;

        min = arr[0];
        for (int i = 1; i < arr.length; i++)
        {
            if (arr[i] < min)
                min = arr[i];
        }
        return (min);
    }
    
    public static double ft_average(double[] arr)
    {
        double sum;

        sum = 0;
        for (int i = 0; i < arr.length; i++)
            sum += arr[i];
        return (sum / arr.length);
    }

    public static void main(String[] args)
    {
        double[] arr = new double[(int)(Math.random() * 100)];

        for (int i = 0; i < arr.length; i++) 
        {
            arr[i] = Math.random() * 100;
        }
        System.out.println("max = " + ft_max(arr));
        System.out.println("min = " + ft_min(arr));
        System.out.println("average = " + ft_average(arr));
    }
}