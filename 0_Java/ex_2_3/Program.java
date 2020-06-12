import java.util.*;

class Incremenator extends Thread
{
	private volatile boolean mIsIncrement = true;

	public void changeAction()
	{
		mIsIncrement = !mIsIncrement;
	}

	@Override
	public void run()
	{
		do
		{
			if(!Thread.interrupted())
			{
				if(mIsIncrement)
					Program.mValue++;
				else
					Program.mValue--;

				System.out.print(Program.mValue + " ");
			}
			else
				return ;

			try{
				Thread.sleep(1000);
			}catch(InterruptedException e){
				return ;
			}
		}
		while(true);
	}
}


public class Program
{
	public static int mValue = 0;

	static Incremenator mInc;

	public static void main(String[] args)
	{
		mInc = new Incremenator();

		System.out.print("Значение = ");
		mInc.start();
		for(int i = 1; i <= 4; i++)
		{
			try{
				Thread.sleep(i*2*1000);
			}catch(InterruptedException e){}

			mInc.changeAction();
			if (i == 4)
				System.out.println();
		}

		mInc.interrupt();
	}
}
