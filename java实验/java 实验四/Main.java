import com.sun.source.tree.Tree;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.*;
import java.awt.*;
import java.util.Timer;
import java.util.jar.JarEntry;

class myframe extends JFrame{
    public myframe(){
        setFont(new Font("微软雅黑",Font.BOLD,14));
        setLayout(new FlowLayout());
        setSize(1800,200);
        setTitle("Test");
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}
class loginPanel extends JPanel{
    JTextField username = new JTextField("Enter name");
    JTextField passwd = new JTextField("Enter password");
    JButton login = new JButton("LOGIN");
    JLabel wrong = new JLabel("Wrong user name or passwd!!");
    public loginPanel(){
        setVisible(false);
        setFont(new Font("微软雅黑",Font.BOLD,14));
        add(username);
        add(passwd);
        add(login);
        add(wrong);
        wrong.setVisible(false);
        login.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = username.getText();
                String password = passwd.getText();
                if(Main.data.containsKey(name)&&Main.data.get(name).password.equals(password)) {
                    setVisible(false);
                    Main.test.setVisible(true);
                }
                else wrong.setVisible(true);
            }
        });
    }
}
class pass extends JPanel{
    JButton IDX = new JButton("choose");
    JTextField id = new JTextField(20);
    JLabel [] his = new JLabel[10];
    public pass(){
        setVisible(false);
        add(IDX);
        add(id);
        setLayout(new GridLayout(4,4,10,10));
        for(int i =0;i<10;i++) {
            his[i] = new JLabel();
            add(his[i]);
        }
        IDX.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int index = Integer.valueOf(id.getText());
                for(int i = 0;i<10;i++){
                    pair tmp = testPanel.N.history.get(index);
                    String dis = tmp.problem[i] + " = " + tmp.res[i] + " "+ (tmp.res[i]==tmp.ans[i]?"right":"wrong");
                    his[i].setText(dis);
                }
            }
        });
    }
}
class regiPanel extends JPanel{
    JTextField username = new JTextField("Enter name");
    JTextField phone = new JTextField("Enter phone");
    JTextField password = new JTextField("Enter password");
    JButton regi = new JButton("Register");
    JLabel wrong = new JLabel("wrong phone number");
    public regiPanel(){
        setVisible(false);
        add(username);
        add(phone);
        add(password);
        add(regi);
        add(wrong);
        wrong.setVisible(false);
        regi.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = username.getText();
                String phon = phone.getText();
                String pass = password.getText();
                if(phon.length()==11){
                    setVisible(false);
                    Main.menu.setVisible(true);
                    Main.data.put(name,new user(name,phon,pass));
                }
                else wrong.setVisible(true);
            }
        });
    }
}
class menuPanel extends JPanel{
    JButton login = new JButton("Login");
    JButton regi = new JButton("Register");
    JButton forget = new JButton("Forget Passwd");
    JButton pass = new JButton("history");
    public menuPanel(){
        setVisible(true);
        setFont(new Font("微软雅黑",Font.BOLD,14));
        add(login);add(regi);add(forget);add(pass);
        login.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                setVisible(false);
                Main.login.setVisible(true);
            }
        });
        regi.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                setVisible(false);
                Main.register.setVisible(true);
            }
        });
        forget.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                setVisible(false);
                Main.forget.setVisible(true);
            }
        });
        pass.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                setVisible(false);
                Main.pass.setVisible(true);
            }
        });
    }
}
class testPanel extends JPanel{
    JButton ASK = new JButton("ASk");
    JButton re = new JButton("do again");
    JButton swap = new JButton("begin/swap test");
    JButton submitbutton = new JButton("submit");
    JLabel rank = new JLabel();
    JLabel score = new JLabel();
    JLabel timing = new JLabel();
    JTextField range = new JTextField("range");
    JLabel [] Problem = new JLabel[10];
    JTextField [] Handin = new JTextField[10];
    JLabel [] res = new JLabel[10];
    JButton quit = new JButton("QUIT");
    JLabel user = new JLabel("NULL");
    int total = 120;
    int idx =0;
    ActionListener pa = new ActionListener(){
        public void actionPerformed(ActionEvent e){
            timing.setText(Integer.toString(total--));
        }
    };
    javax.swing.Timer timer = new javax.swing.Timer(1000,pa);
    static numget N = new numget();
    public testPanel(String name){
        setFont(new Font("微软雅黑",Font.BOLD,14));
        setLayout(new FlowLayout());
        setVisible(false);
        rank.setVisible(false);
        user.setForeground(Color.blue);
        user.setText(name);
        add(user);
        add(range);
        add(re);
        add(swap);
        add(submitbutton);
        add(ASK);
        for(int i = 0 ;i<10;i++){
            Problem[i] = new JLabel("Problem");
            Handin[i] = new JTextField(5);
            res[i] = new JLabel();
            add(Problem[i]);add(Handin[i]);add(res[i]);res[i].setVisible(false);
        }
        add(rank);
        add(score);
        add(timing);
        add(quit);
        ASK.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new clientframe();
            }
        });
        quit.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Main.cnt--;
                setVisible(false);
                Main.CHK.remove(name);
            }
        });
        swap.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                N.mx = Integer.valueOf(range.getText());
                total = 120;
                timer.start();
                rank.setVisible(false); score.setVisible(false);
                N.get();
                for(int i = 0;i<10;i++){
                    Problem[i].setText(N.history.get(N.idx-1).problem[i]);
                }
            }
        });
        re.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                total = 120;
                idx = 0;
                N.history.get(N.idx-1).score = 0;
                timer.start();
            }
        });

        submitbutton.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                timer.stop();
                pair tt = N.history.get(N.idx-1);
               for(int i = 0;i<10;i++){
                   int tans = Integer.valueOf( Handin[i].getText());
                   tt.res[i] = tans;
                   res[i].setText(tans==tt.ans[i]?"right":"wrong");res[i].setVisible(true);
                   tt.score += tans == tt.ans[i] ? 10 : 0;
               }
               score.setText(""+tt.score);
               if(tt.score>=80)rank.setText("good");
               else if(tt.score>=60) rank.setText("not bad");
               else rank.setText("bad");
               score.setVisible(true);
               rank.setVisible(true);
            }
        });
    }
}
class forget extends  JPanel{
    JButton change = new JButton("change");
    JTextField name = new JTextField("name");
    JTextField phone = new JTextField("phone");
    JTextField pass = new JTextField("password");
    JLabel wrong = new JLabel();
    public forget(){
        add(change);
        add(name);
        add(phone);
        add(pass);
        add(wrong);
        setVisible(false);
        change.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String tname = name.getText();
                String tphone = phone.getText();
                if(Main.data.containsKey(tname)&&Main.data.get(tname).phone.equals(tphone)){
                    Main.data.get(tname).password = pass.getText();
                    wrong.setText("change successed !");
                }
                else {
                    wrong.setText("wrong name or phone number");
                }
            }
        });

    }
}
public class Main {
    static int cnt = 0;
    static menuPanel menu = new menuPanel();
    static loginPanel login = new loginPanel();
    static regiPanel register = new regiPanel();
    static testPanel test = new testPanel("Single user");
    static myframe frame = new myframe();
    static pass pass = new pass();
    static TreeMap<String,user> data = new TreeMap<String,user>();
    static forget forget = new forget();
    static TreeMap<String,Boolean> CHK = new TreeMap<>();
    public static synchronized void  AddUser(String name) throws InterruptedException {
        if(cnt < 3&&!CHK.containsKey(name)) {
            Thread.sleep(1000);
            System.out.println(name + "   login succeed");
            cnt ++;
            CHK.put(name,true);
            testPanel tt = new  testPanel(name);
            tt.setVisible(true);
            frame.add(tt);
            frame.setVisible(true);
        }
        else {
            System.out.println(name +"   login failed");
        }
    }
    public static void main(String[] args) {

        JButton retur = new JButton("return to menu");
        JButton loginall = new JButton("login all");
        loginall.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Vector<String> Name = new Vector<>();
               try{
                   BufferedReader br = new BufferedReader (new FileReader("C:\\Users\\Colacat\\IdeaProjects\\test\\src\\account.txt"));
                   String name = "";
                   while((name=br.readLine())!=null){
                       Name.add(name);
                   }
               }catch (Exception ex){}
               for(String t : Name){
                   Thread tmp = new Thread(()->{
                       try {
                           System.out.println(t+"   query for login");
                           AddUser(t);
                       } catch (InterruptedException ex) {
                           throw new RuntimeException(ex);
                       }

                   });
                   tmp.start();
               }
            }
        });
        retur.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                menu.setVisible(true);
                login.setVisible(false);
                register.setVisible(false);
                test.setVisible(false);
                pass.setVisible(false);
                forget.setVisible(false);
            }
        });
        frame.add(retur);
        frame.add(menu);
        frame.add(login);
        frame.add(register);
        frame.add(test);
        frame.add(pass);
        frame.add(forget);
        frame.add(loginall);
        frame.setVisible(true);
    }
}