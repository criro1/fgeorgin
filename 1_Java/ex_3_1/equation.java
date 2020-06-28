import java.util.*;

class equation
{
    static double function(double x)
    {
        return (Math.cos(Math.pow(x, 5)) + Math.pow(x, 4) - 345.3 * x - 23);
    }

    static double ft_fin(double l, double r, double eps)
    {
        double m;

        if (r - l <= eps)
            return (l);
        m = (l + r) / 2;
        if (Math.signum(function(l)) != Math.signum(function(m)))
            return (ft_fin(l, m, eps));
        else
            return (ft_fin(m, r, eps));
    }

    static double ft_solve(double l, double r, double eps)
    {
        double res;
        if (Math.signum(function(l)) == Math.signum(function(r)))
        {
            System.out.println("Error, there is not any roots");
            System.exit(0);
        }
        return (ft_fin(l, r, eps));
    }

    public static void main(String[] args)
    {
        double res;

        res = ft_solve(0, 10, 0.001);
        System.out.println("the root = " + res);
    }
}