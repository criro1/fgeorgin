import java.util.*;

class shape
{
    private double volume;

    public shape(double volume)
    {
        this.volume = volume;
    }

    public double getVolume()
    {
        return (volume);
    }
}

class solidOfRevolution extends shape
{
    private double radius;

    public solidOfRevolution(double radius, double volume)
    {
        super(volume);
        this.radius = radius;
    }

    public double getRadius()
    {
        return (radius);
    }
}

class ball extends solidOfRevolution
{
    public ball(double radius)
    {
        super(radius, (4/3 * Math.PI *Math.pow(radius, 3)));
    }
}

class cylinder extends solidOfRevolution
{
    private double height;

    public cylinder(double height, double radius)
    {
        super(radius, (Math.PI * Math.pow(radius, 2) * height));
        this.height = height;
    }
}

class pyramid extends shape
{
    private double s;
    private double h;

    public pyramid(double s, double h)
    {
        super(4 / 3 * s * h);
        this.s = s;
        this.h = h;
    }
}

class box extends shape
{
    private ArrayList<shape> box_of_shapes = new ArrayList<shape>();
    double free;

    public box(double free)
    {
        super(free);
        this.free = free;
    }

    public boolean add_f(shape sh)
    {
        if (free >= sh.getVolume())
        {
            box_of_shapes.add(sh);
            free = free - sh.getVolume();
            return (true);
        }
        else
            return (false);
    }
}

class main
{
    public static void main(String[] args)
    {
        ball bl = new ball(3);
        cylinder cyl = new cylinder(3, 2.5);
        pyramid pyr = new pyramid(9, 8);

        box fig_box = new box(200);

        System.out.println("volume = " + bl.getVolume());
        System.out.println(fig_box.add_f(bl));
        System.out.println("free volume in the box = " + fig_box.free);
        System.out.println("volume = " + cyl.getVolume());
        System.out.println(fig_box.add_f(cyl));
        System.out.println("free volume in the box = " + fig_box.free);
        System.out.println("volume = " + pyr.getVolume());
        System.out.println(fig_box.add_f(pyr));
        System.out.println("free volume in the box = " + fig_box.free);
    }
}