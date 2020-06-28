import java.util.*;

class vector
{
    private double x;
    private double y;
    private double z;

    public vector(double x, double y, double z)
    {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public double ft_len()
    {
        return (Math.sqrt(x*x + y*y + z*z));
    }

    public double ft_scal(vector first)
    {
        return (x * first.x + y * first.y + z * first.z);
    }

    public vector ft_scal_new(vector first)
    {
        return (new vector(
            y * first.z - z * first.y,
            z * first.x - x * first.z,
            x * first.y - y * first.x));
    }

    public static double ft_angle(vector first, vector second)
    {
        return(first.ft_scal(second) / (first.ft_len() * second.ft_len()));
    }

    public vector ft_sum(vector second)
    {
        return(new vector(x + second.x,
            y + second.y,
            z + second.z));
    }

    public vector ft_diff(vector second)
    {
        return(new vector(x - second.x,
            y - second.y,
            z - second.z));
    }

    public static vector[] ft_make_arr(int n)
    {
        vector[] arr = new vector[n];
        for(int i = 0; i < n; i++)
        {
            arr[i] = new vector(Math.random() * 50,
            Math.random() * 50, Math.random() * 50);
        }
        return (arr);
    }

    public static void main(String[] args)
    {
        vector first = new vector((int)(Math.random() * 50),
            (int)(Math.random() * 50), (int)(Math.random() * 50));
        vector second = new vector((int)(Math.random() * 50),
            (int)(Math.random() * 50), (int)(Math.random() * 50));
        System.out.println("first vector's lenght = " + first.ft_len());
        System.out.println("second vector's lenght = " + second.ft_len());
        System.out.println("scalar product = " + first.ft_scal(second));
        System.out.println((first.ft_scal_new(second)).toString());
        System.out.println("cos = " + ft_angle(first, second));
        System.out.println("sum = " + (first.ft_sum(second)).toString());
        System.out.println("difference = " + (first.ft_diff(second)).toString());
        vector[] vectors = ft_make_arr(2);
    }

    @Override
    public String toString()
    {
        return "vector{" +
                "x = " + x +
                ", y = " + y +
                ", z = " + z + "}";
    }
}