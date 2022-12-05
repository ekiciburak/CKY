public class Main {

	public static void main(String[] args) {

		boolean b;
		//String s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
		//String s = "baaba"; // test it with the grammar discussed in the class; see cky.java file
		String s = "aabaababaabaa";
		cky c = new cky();
		
		System.out.printf("input string s: %s", s);
		System.out.println();
		
		b = c.ckyAlg(s); //calling the CKY parser.
		
		System.out.printf("s in L(G): ");
		if(b)
			System.out.println("yes");
		else
			System.out.println("no");
	}

}
