class ex_1_1
{
    public static int[] ft_bubble_sort(int[] arr)
    {
        int third;

        third = arr[0];
        for (int i = 0; i < arr.length - 1; i++)
        {
            for (int j = 1; j < arr.length; j++)
            {
                if (arr[j - 1] > arr[j])
                {
                    third = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = third;
                }
            }                
        }
        return (arr);
    }

    public static void main(String[] args)
    {
        int[] arr = new int[(int)(Math.random() * 100)];

        for (int i = 0; i < arr.length; i++) 
        {
            arr[i] = (int)(Math.random() * 100);
        }
        ft_bubble_sort(arr);
        for (int i = 0; i < arr.length; i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}