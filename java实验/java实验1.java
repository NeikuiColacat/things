import javax.swing.*;
import java.util.*;
import java.awt.*;

class numget {
    static Scanner in = new Scanner(System.in);
    int mn,mx,n1,n2,mode,ans;
    Random tt = new Random();
    public numget(){
        System.out.println("Plz set the range you need !");
        System.out.println("lower bound :");mn = in.nextInt();System.out.println("upper bound :");mx = in.nextInt();
    }
    void renum() {
        n1 = tt.nextInt(mx-mn)+1+mn;
        n2 = tt.nextInt(mx-mn) +1+mn;
        if(n1 < n2){int tmp = n1;n1=n2;n2=tmp;}
    }
    void remode() {
        mode=tt.nextInt(4);
        while(mode==3&&n2==0)n2 = tt.nextInt(mx-mn) + 1+mn;
        switch(mode){
            case 0->ans=n1+n2;
            case 1->ans = n1-n2;
            case 2->ans=n1*n2;
            case 3->ans=n1/n2;
        }
    }
}
class user{
    String name,phone,password;
    user(String name,String phone,String password){this.name = name ; this.phone = phone; this.password = password;}
}
public class Main {
    static void divi(){System.out.println("----------------\n----------------");}
    static void IL(){System.out.println("illegal value , plz enter again !");}
    static boolean menu(){
        System.out.println("Plz choose the operation you need \n 1 for login \n 2 for register \n 3 for change password \n 4 for quit");
        int x = in.nextInt();boolean fl = true;
        switch (x) {
            case 1 -> login();
            case 2 -> register();
            case 3 -> change();
            case 4 -> fl = false;
        }
        divi();return fl;
    }
    static void login(){
        while(true){
            System.out.println("Please enter your name and passwd");
            tname = in.next();tpass=in.next();
            if(data.containsKey(tname)&&data.get(tname).password.equals(tpass)){System.out.println("login succeed!");divi();break;}
            else IL();
        }test();
    }
    static void register(){
        System.out.println("Enter the name , password  and phone number ");
        tname = in.next();tpass = in.next();tphone = in.next();
        while(tphone.length()!=11){System.out.println("Wrong number ! Enter again");tphone = in.next();}
        data.put(tname,new user(tname,tphone,tpass));
        System.out.println("Registration Completed!");
    }
    static void change(){
        while(true) {
            System.out.println("Plz enter the name and phone number !");
            tname = in.next();
            tphone = in.next();
            if(data.containsKey(tname)&&data.get(tname).phone.equals(tphone)){
                System.out.println("Authorization succeeded . Plz enter the new password");
                tpass = in.next();
                data.replace(tname,new user(tname,tphone,tpass));
                System.out.println("Password changed!");
                break;
            } else {IL();divi();}
        }
    }
    static void test(){
        numget num = new numget();
        System.out.println("TEST BEGIN!!!");
        int score=0;
        for(int i = 1;i<=3;i++){
            num.renum();num.remode();
            divi();System.out.println(num.n1+" "+modeMap[num.mode]+" "+num.n2);divi();
            System.out.println("Enter ans:");score += in.nextInt()==num.ans?10:0;
        }
        System.out.println("TEST FINISHED!!!\nscore:"+score+"\nRank:");
        if(score>=80)System.out.println("GOOD!");
        else if(score>=60) System.out.println("Passed , but not good enough");
        else System.out.println("NOT GOOD");
        System.out.println("keep going ?");if(in.nextBoolean())test();
    }
    static TreeMap<String,user> data = new TreeMap<String,user>();
    static Scanner in = new Scanner(System.in);
    static String tname,tpass,tphone;
    static  char [] modeMap = { '+', '-', '*', '/' };
    public static void main(String[] args) {
        while(menu());
    }
}