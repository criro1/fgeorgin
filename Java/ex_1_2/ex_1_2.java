class ex_1_2
{
    public static boolean ft_prime(int num)
    {
        int i;
        int count;

        i = 2;
        count = 0;
        while (i <= num)
        {
            if (num % i == 0)
                count++;
            if (count >= 2)
                break ;
            i++;
        }
        return (count == 1 ? true : false);
    }

    public static void main(String[] args)
    {
        for(int num = 2; num < 101; num++)
        {
            if (ft_prime(num))
                System.out.print(num + " ");
        }
        System.out.println();
    }
}