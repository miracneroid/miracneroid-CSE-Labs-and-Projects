/*
3. ImageSelectionApp
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

public class ImageSelectionApp extends JFrame {
    private JPanel mainPanel;
    private JLabel imageLabel;

    public ImageSelectionApp() {
        setTitle("Image Selection App");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 400);

        mainPanel = new JPanel();
        mainPanel.setLayout(new BorderLayout());

        imageLabel = new JLabel();
        mainPanel.add(imageLabel, BorderLayout.CENTER);

        JButton selectImageButton = new JButton("Select Image");
        selectImageButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                selectImage();
            }
        });

        mainPanel.add(selectImageButton, BorderLayout.SOUTH);

        add(mainPanel);
        setVisible(true);
    }

    private void selectImage() {
        JFileChooser fileChooser = new JFileChooser();
        int result = fileChooser.showOpenDialog(this);

        if (result == JFileChooser.APPROVE_OPTION) {
            File selectedFile = fileChooser.getSelectedFile();
            ImageIcon imageIcon = new ImageIcon(selectedFile.getPath());
            Image image = imageIcon.getImage().getScaledInstance(300, 300, Image.SCALE_SMOOTH);
            imageIcon = new ImageIcon(image);
            imageLabel.setIcon(imageIcon);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new ImageSelectionApp();
            }
        });
    }
}
