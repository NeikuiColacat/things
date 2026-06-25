import java.util.Random;
import java.util.Scanner;
import java.util.Vector;

class pair{
    String[] problem = new String[10];
    int[] ans = new int[10];
    int[] res = new int[10];
    int score = 0;
}
public class numget {
    int mx=10,n1,n2,mode,ans,idx=0;
    char [] Mode = {'+','-','*','/'};
    Vector<pair> history = new Vector<pair>();
    Random tt = new Random();
    pair tmp;
    void get(){
        pair tmp = new pair();
        history.add(tmp);
        for(int i = 0 ;i<10;i++){
            renum();remode();
            tmp.problem[i] = n1+" " + Mode[mode] + " " + n2;
            tmp.ans[i] = ans;
        }
        idx++;
    }
    void renum() {
        n1 = tt.nextInt(mx);
        n2 = tt.nextInt(mx);
        if(n1 < n2){int tmp = n1;n1=n2;n2=tmp;}
    }
    void remode() {
        mode=tt.nextInt(4);
        while(mode==3&&n2==0)n2 = tt.nextInt(mx);
        switch(mode){
            case 0->ans=n1+n2;
            case 1->ans = n1-n2;
            case 2->ans=n1*n2;
            case 3->ans=n1/n2;
        }
    }
}