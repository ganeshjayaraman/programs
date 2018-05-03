import java.io.*;
import java.lang.*;

public class StringTest  {
	public static void main(String[] args) {
		String s = new String("ganesh");
		char[] s1 = new char[]{'g','a','n','e','s','h'};

		System.out.println(s);
		System.out.println("" + s1);

		s = s + " Jayaraman";

		System.out.println(s);
	}
}