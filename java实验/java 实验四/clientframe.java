import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class clientframe extends JFrame {
    JPanel up = new JPanel();
    JPanel down = new JPanel();
    JButton connect = new JButton("connect");
    JTextField ip = new JTextField("127.0.0.1", 10);
    JTextField port = new JTextField("123", 10);
    JTextArea MEG = new JTextArea();
    JTextField input = new JTextField(30);
    JButton send = new JButton("send");
    Socket Client;

    public void connect() throws IOException {
        String targetip = ip.getText(), targetport = port.getText();
        int Port = Integer.parseInt(targetport);
        Client = new Socket(targetip, Port);
        new ClientThread(Client, this).start();
        MEG.append("connect with server succeed !\n");
    }

    public void send() throws IOException {
        PrintStream i = new PrintStream(Client.getOutputStream());
        i.println("from "+port.getText()+"\n"+input.getText());
        MEG.append("client : " + input.getText() + "\n");
        input.setText("");
    }

    public clientframe() {
        setLayout(new BorderLayout());
        up.add(ip);
        up.add(port);
        up.add(connect);
        down.add(input);
        down.add(send);
        this.add(BorderLayout.NORTH, up);
        this.add(BorderLayout.CENTER, MEG);
        this.add(BorderLayout.SOUTH, down);
        setBounds(500, 500, 500, 500);
        setVisible(true);
        connect.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    connect();
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            }
        });
        send.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    send();
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            }
        });

    }
}

class ClientThread extends Thread {
    Socket client;
    clientframe CF;
    public ClientThread(Socket a, clientframe b) {
        client = a;
        CF = b;
    }
    public void run() {
        try {
            DataInputStream i = new DataInputStream(client.getInputStream());
            InputStreamReader j = new InputStreamReader(i);
            BufferedReader k = new BufferedReader(j);
            String tmp = "";
            while ((tmp = k.readLine()) != null) {
                CF.MEG.append("from server :" + tmp + "\n");
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}
