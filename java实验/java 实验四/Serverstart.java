import com.sun.source.tree.Tree;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.*;
import java.net.Inet4Address;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.ArrayList;
import java.util.TreeMap;

class Server extends JFrame {
    JTextField input = new JTextField(20);
    JTextField port = new JTextField(5);
    JTextArea MEG = new JTextArea();
    JButton send = new JButton("send");
    TreeMap<Integer, Socket> Ports = new TreeMap<>();
    int[] ports = {800, 801, 802, 803};
    public void send() {
        try {
            Socket server = Ports.get(Integer.parseInt(port.getText()));
            PrintStream i = new PrintStream(server.getOutputStream());
            i.println(input.getText());
            MEG.append("server: " + input.getText() + "\n");
            input.setText("");
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
    }

    public Server() throws IOException {
        setLayout(new BorderLayout());
        add(BorderLayout.CENTER, MEG);
        add(BorderLayout.SOUTH, input);
        add(BorderLayout.EAST, port);
        add(BorderLayout.NORTH, send);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        send.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                send();
            }
        });
        setBounds(500, 500, 500, 500);
        setVisible(true);
        for (int i : ports) {
            new ServerThread(this, i).start();
        }
    }
}

class ServerThread extends Thread {
    Server that;
    int port;
    public ServerThread(Server a, int P) {
        that = a;
        port = P;
    }

    public void run() {
        try {
            ServerSocket ss = new ServerSocket(port);
            that.MEG.append("listening " + port + "\n");
            while(true) {
                Socket server = ss.accept();
                that.Ports.put(port, server);
                DataInputStream i = new DataInputStream(server.getInputStream());
                InputStreamReader j = new InputStreamReader(i);
                BufferedReader k = new BufferedReader(j);
                String tmp = "";
                while ((tmp = k.readLine()) != null) {
                    that.MEG.append("client: " + tmp + "\n");
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

public class Serverstart {
    public static void main(String[] agrs) throws IOException {
        new Server();
    }
}
