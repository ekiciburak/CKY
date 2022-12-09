public class Main {

	public static void main(String[] args) {

		boolean b;
		//String s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"; // test with grammar2.txt file.		
		//String s = "baaba"; // test it with grammar.txt file. 
		String s = "aaabaabaabaaa"; // test it with palindrome_grammar.txt file.
		String path = "palindrome_grammar.txt"; // path to the grammar file that contains production rules.
		/**
			The file looks like this:
			S -> CA|DB|AA|BB|a|b
			A -> a
			B -> b
			C -> AS
			D -> BS
		
		 */
		
		cky c = new cky();
		
		System.out.printf("input string s: %s", s);
		System.out.println();
		
		b = c.ckyAlg(s,path); //calling the CKY parser.
		
		System.out.printf("s in L(G): ");
		if(b)
			System.out.println("yes");
		else
			System.out.println("no");
	}

}
