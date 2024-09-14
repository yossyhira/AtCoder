import java.util.*;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String AB = sc.next();
        String AC = sc.next();
        String BC = sc.next();
        sc.close();

        String[] ABC = {"A", "B", "C"};
        int AIdx = 0,BIdx = 0, CIdx = 0;

        if(AB.equals(">")){
            for(int i = 0; i < 3; i++){
                if(ABC[i] == "A"){
                    AIdx = i; 
                }
                if(ABC[i] == "B"){
                    BIdx = i; 
                }
            }
            if(AIdx < BIdx){
                String hoge = ABC[AIdx];
                ABC[AIdx] = ABC[BIdx];
                ABC[BIdx] = hoge;
            } 
        }else{
            for(int i = 0; i < 3; i++){
                if(ABC[i] == "A"){
                    AIdx = i; 
                }
                if(ABC[i] == "B"){
                    BIdx = i; 
                }
            }
            if(AIdx > BIdx){
                String hoge = ABC[AIdx];
                ABC[AIdx] = ABC[BIdx];
                ABC[BIdx] = hoge;
            } 
        }
        if(AC.equals(">")){
            for(int i = 0; i < 3; i++){
                if(ABC[i] == "A"){
                    AIdx = i; 
                }
                if(ABC[i] == "C"){
                    CIdx = i; 
                }
            }
            if(AIdx < CIdx){
                String hoge = ABC[AIdx];
                ABC[AIdx] = ABC[CIdx];
                ABC[CIdx] = hoge;
            } 
        }else{
             for(int i = 0; i < 3; i++){
                if(ABC[i] == "A"){
                    AIdx = i; 
                }
                if(ABC[i] == "C"){
                    CIdx = i; 
                }
            }
            if(AIdx > CIdx){
                String hoge = ABC[AIdx];
                ABC[AIdx] = ABC[CIdx];
                ABC[CIdx] = hoge;
            } 
        }
        if(BC.equals(">")){
            for(int i = 0; i < 3; i++){
                if(ABC[i] == "B"){
                    BIdx = i; 
                }
                if(ABC[i] == "C"){
                    CIdx = i; 
                }
            }
            if(BIdx < CIdx){
                String hoge = ABC[BIdx];
                ABC[BIdx] = ABC[CIdx];
                ABC[CIdx] = hoge; 
            }
        }else{
            for(int i = 0; i < 3; i++){
                if(ABC[i] == "B"){
                    BIdx = i; 
                }
                if(ABC[i] == "C"){
                    CIdx = i; 
                }
            }
            if(BIdx > CIdx){
                String hoge = ABC[BIdx];
                ABC[BIdx] = ABC[CIdx];
                ABC[CIdx] = hoge; 
            }
        }

        System.out.println(ABC[1]);
        
    }
}