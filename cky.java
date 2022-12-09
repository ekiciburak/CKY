import java.util.HashMap;
import java.io.File;
import java.util.Scanner;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;


public class cky {
	/*
	 * //grammar G in CNF s.t. L(G) = { a^ib^i | i > 0 }.
	 * String [] S = {"AC", "AB"};
	 * String [] A = {"a"};
	 * String [] B = {"b"};
	 * String [] C = {"SB"};    
	 */
	
	/*
	 * //example discussed in the class
	 * String [] S = {"AB", "BC"};
	 * String [] A = {"BA", "a"};
	 * String [] B = {"CC", "b"};
	 * String [] C = {"AB", "a"};
     
	
	 //grammar G in CNF s.t. L(G) = { x \in {a,b}* | x is palindrome }
      String [] S = {"CA", "DB", "AA", "BB", "a", "b"};
      String [] A = {"a"};
      String [] B = {"b"};
      String [] C = {"AS"};
      String [] D = {"BS"};
	 */

    int size = 50; // have the size larger if the string length is "very" long.
    
    //auxiliary arrays
	String [] ACC  = new String[20]; 
    String [] ACC1 = new String[20]; 
    String [] ACC2 = new String[20]; 
    String [] BCC  = new String[20]; 
	Map<String, String[]> grammar = new HashMap<String, String[]>();

	public void readGrammar (String path){
		List <String> lines = new ArrayList <String> ();
		try{
			File file = new File(path);
			Scanner sc = new Scanner(file);
		while (sc.hasNextLine()){
			String line = sc.nextLine();
			lines.add(line);
		
		}	
		for (String line : lines){
			String[] elem = line.split("->");
			String key = elem[0].strip().trim();
			String[] value = elem[1].strip().split("\\|");
			this.grammar.put(key,value);
		}
		for (String key : this.grammar.keySet()){
			List <String> temp = new ArrayList <String> ();
			for(String value : this.grammar.get(key)){
				temp.add(value.strip().trim());
			}
			this.grammar.put(key, temp.toArray(new String[temp.size()]));
		}
		}
		catch (Exception e){
			System.out.println(e);
		}
		
	}

  
    public String[] search (String s)
    {

        String [] ACC = new String[size]; 
    	int k = 0;
    	
		for (Map.Entry<String, String[]> entry : this.grammar.entrySet()) {
			String key = entry.getKey();
			String [] values = entry.getValue();
			for (String value : values){
				if (s.equals(value)){
					ACC[k] = key;
					k++;
				}
			}
		}
		
		return ACC;
    }
    
    public int lenc (String [] s)
    {
    	int i;
    	for (i=0; s[i] != null; i++);
    	return i;
    }
    
    public String[] concat (String [] s1, String [] s2)
    {
    	int l1 = lenc(s1);
    	int l2 = lenc(s2);
        String [] ACC = new String[size];
        int k = 0;  
        for (int i = 0; i < l1; i++) 
        {
    		for (int j = 0; j < l2; j++)
			{
				ACC[k] = s1[i].concat(s2[j]);
    			k++;
			}  			
        }
    	return ACC;
    }
    
    public String[] append (String [] s1, String [] s2)
    {
    	int l1 = lenc(s1);
    	int l2 = lenc(s2);
        String [] ACC = new String[l1+l2+1];
        int j = 0;
        
        if (l1 == 0)
        	ACC = s2;
        else if (l2 == 0)
        	ACC = s1;
        else
        {
            for (int i = 0; i < l1+l2; i++)
			{
				if (i < l1)
				ACC[i] = s1[i];
				else
				{
					ACC[i] = s2[j];
					j++;
				}
			}     	
        }
        return ACC;
    }
    
    public void clear (String [] s)
    {
    	int l1 = lenc(s);
    	for (int i = 0; i < l1; i++)
			s[i] = null;
    }
 
    public Boolean isIn (String [] s, String e)
    {
    	Boolean b = false;
    	int l = s.length;
    	for (int i = 0; i < l && s[i] != null; i++)
		{
    		if (s[i].equals(e))
				b = true;
		}
    	return b;
    }
    
    public String [] removeDups (String [] s)
    {
    	int k = 0;
    	int l = s.length;
    	String [] acc = new String[l];
    	for (int i = 0; s[i] != null; i++)
		{
			if(!isIn(acc, s[i]))
    		{
    			acc[k] = s[i];
    			k++;
			}
		}
    	return acc;
    }
    
    
    //CKY parser
    public Boolean ckyAlg (String s,String path)
    {
        int index = s.length()+1;
        int l = s.length();
        Boolean b = false;
        
        //2-dim array (of strings -> [3-dim indeed]) storing non-terminals generating substrings of s.
        String [][][] T = new String[index][index][size];
        this.readGrammar(path);
		for (int i = 0; i < s.length(); i++) {
			T[i][i+1] = search(Character.toString(s.charAt(i)));
		}
		
		for (int u = 2; u < index; u++) 
		{
			for (int m = 0; m < index-u; m++) 
			{
				for (int i = 1; i < u; i++) 
				{
					BCC = concat(T[m][m+i], T[m+i][m+u]);
					ACC = append(ACC, BCC);
				}
				for (int i = 0; ACC[i] != null; i++) 
				{
					ACC1 = search(ACC[i]);
					if(ACC1[0] != null)
						ACC2 = append(ACC2, ACC1);
				}
				ACC2 = removeDups(ACC2);
				T[m][m+u] = ACC2.clone();
				clear(ACC2);
				clear(BCC);
				clear(ACC);
			}
		}
		
		System.out.printf("list of non-terminals generating s: ");
		for (int m = 0; T[0][l][m] != null; m++)
		{
			System.out.printf("%s ", T[0][l][m]);
			if (T[0][l][m].equals("S"))
				b = true;
		} 
		System.out.println();
		return b;
    }
}
