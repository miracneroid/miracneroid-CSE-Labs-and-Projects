import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class MouseAdapterExample extends JFrame {
    private JPanel mainPanel;

    public MouseAdapterExample() {
        setTitle("MouseAdapter Example");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 400);

        mainPanel = new JPanel();
        mainPanel.setBackground(Color.WHITE);

        // Using MouseAdapter to handle mouse events
        mainPanel.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                // Change the background color on mouse click
                changeBackgroundColor();
            }
        });

        add(mainPanel);
        setVisible(true);
    }

    private void changeBackgroundColor() {
        // Generate a random color
        Color randomColor = new Color(
                (int) (Math.random() * 256),
                (int) (Math.random() * 256),
                (int) (Math.random() * 256)
        );

        // Set the background color of the mainPanel
        mainPanel.setBackground(randomColor);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new MouseAdapterExample();
            }
        });
    }
}
