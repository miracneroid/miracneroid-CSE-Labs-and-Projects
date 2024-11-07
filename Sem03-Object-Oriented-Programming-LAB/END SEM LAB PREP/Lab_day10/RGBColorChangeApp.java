import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class RGBColorChangeApp extends JFrame {
    private JPanel mainPanel;
    private JComboBox<Integer> redComboBox, greenComboBox, blueComboBox;
    private JButton changeColorButton;

    public RGBColorChangeApp() {
        setTitle("RGB Color Change App");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 400);

        mainPanel = new JPanel();
        mainPanel.setLayout(new BorderLayout());

        redComboBox = createColorComboBox();
        greenComboBox = createColorComboBox();
        blueComboBox = createColorComboBox();

        JPanel comboPanel = new JPanel();
        comboPanel.add(new JLabel("Red:"));
        comboPanel.add(redComboBox);
        comboPanel.add(new JLabel("Green:"));
        comboPanel.add(greenComboBox);
        comboPanel.add(new JLabel("Blue:"));
        comboPanel.add(blueComboBox);

        changeColorButton = new JButton("Change Color");
        changeColorButton.addActionListener(new ChangeColorButtonClickListener());

        mainPanel.add(comboPanel, BorderLayout.NORTH);
        mainPanel.add(changeColorButton, BorderLayout.SOUTH);

        add(mainPanel);
        setVisible(true);
    }

    private JComboBox<Integer> createColorComboBox() {
        Integer[] values = new Integer[256];
        for (int i = 0; i < 256; i++) {
            values[i] = i;
        }
        return new JComboBox<>(values);
    }

    private class ChangeColorButtonClickListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            int red = (int) redComboBox.getSelectedItem();
            int green = (int) greenComboBox.getSelectedItem();
            int blue = (int) blueComboBox.getSelectedItem();

            Color selectedColor = new Color(red, green, blue);
            mainPanel.setBackground(selectedColor);
        }
    }
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new RGBColorChangeApp();
            }
        });
    }
}