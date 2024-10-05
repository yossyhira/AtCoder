import java.util.*;


public class b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        String T = sc.next();
        sc.close();

        char[] s = S.toCharArray();
        char[] t = T.toCharArray();

        if(S.length() <= T.length()){
            for (int i = 0; i < S.length(); i++) {
                if(S.length() == T.length()){
                    if(s[i] != t[i]){
                        System.out.println(i + 1);
                        return;
                    }
                }else{
                    //boolean sim ; 
                    if(s[i] != t[i]){
                        System.out.println(i + 1);
                        return;
                        
                    }
                    if(i == S.length() - 1){
                        if(s[i] == t[i]){
                        System.out.println(i + 2);  
                        return;
                    }
                }
            }        
    }
    }else{
        for (int i = 0; i < T.length(); i++) { 
                    if(s[i] != t[i]){
                        System.out.println(i + 1);
                        return;
                        
                    }
                    if(i == T.length() - 1){
                        if(s[i] == t[i]){
                        System.out.println(i + 2);  
                        return;
                    }
                }
            }       
    }

    System.out.println(0);
}
}