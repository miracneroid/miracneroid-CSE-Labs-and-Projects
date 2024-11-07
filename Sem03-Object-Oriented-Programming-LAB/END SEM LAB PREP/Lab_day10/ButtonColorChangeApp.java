/*
4. ButtonColorChangeApp
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ButtonColorChangeApp extends JFrame {
    private JPanel mainPanel;
    private JButton button1, button2, button3, button4, button5;

    public ButtonColorChangeApp() {
        setTitle("Button Color Change App");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 400);

        mainPanel = new JPanel();
        mainPanel.setLayout(new BorderLayout());

        button1 = new JButton("Color 1");
        button2 = new JButton("Color 2");
        button3 = new JButton("Color 3");
        button4 = new JButton("Color 4");
        button5 = new JButton("Color 5");

        button1.addActionListener(new ColorButtonClickListener(Color.RED));
        button2.addActionListener(new ColorButtonClickListener(Color.BLUE));
        button3.addActionListener(new ColorButtonClickListener(Color.GREEN));
        button4.addActionListener(new ColorButtonClickListener(Color.YELLOW));
        button5.addActionListener(new ColorButtonClickListener(Color.ORANGE));

        JPanel buttonPanel = new JPanel();
        buttonPanel.add(button1);
        buttonPanel.add(button2);
        buttonPanel.add(button3);
        buttonPanel.add(button4);
        buttonPanel.add(button5);

        mainPanel.add(buttonPanel, BorderLayout.SOUTH);

        add(mainPanel);
        setVisible(true);
    }

    private class ColorButtonClickListener implements ActionListener {
        private Color color;

        public ColorButtonClickListener(Color color) {
            this.color = color;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            mainPanel.setBackground(color);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new ButtonColorChangeApp();
            }
        });
    }
}
