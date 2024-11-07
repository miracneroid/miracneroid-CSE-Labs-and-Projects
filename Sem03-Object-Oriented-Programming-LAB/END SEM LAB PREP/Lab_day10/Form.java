/*
1.  Desingn a Form - containig Fname, lastname address Qualifcation, Skillset, hobbies, gender, image , submitbutton and other field
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

public class Form extends JFrame {
    private JTextField firstNameField, lastNameField, addressField, qualificationField, skillsetField, hobbiesField;
    private JRadioButton maleRadio, femaleRadio;
    private ButtonGroup genderGroup;
    private JButton submitButton, chooseImageButton;
    private JLabel imageLabel;

    public Form() {
        setTitle("User Information Form");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 400);
        setLayout(new GridLayout(11, 2));

        add(new JLabel("First Name:"));
        firstNameField = new JTextField();
        add(firstNameField);

        add(new JLabel("Last Name:"));
        lastNameField = new JTextField();
        add(lastNameField);

        add(new JLabel("Address:"));
        addressField = new JTextField();
        add(addressField);

        add(new JLabel("Qualification:"));
        qualificationField = new JTextField();
        add(qualificationField);

        add(new JLabel("Skillset:"));
        skillsetField = new JTextField();
        add(skillsetField);

        add(new JLabel("Hobbies:"));
        hobbiesField = new JTextField();
        add(hobbiesField);

        add(new JLabel("Gender:"));
        maleRadio = new JRadioButton("Male");
        femaleRadio = new JRadioButton("Female");
        genderGroup = new ButtonGroup();
        genderGroup.add(maleRadio);
        genderGroup.add(femaleRadio);
        JPanel genderPanel = new JPanel();
        genderPanel.add(maleRadio);
        genderPanel.add(femaleRadio);
        add(genderPanel);

        add(new JLabel("Image:"));
        chooseImageButton = new JButton("Choose Image");
        chooseImageButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFileChooser fileChooser = new JFileChooser();
                int result = fileChooser.showOpenDialog(Form.this);
                if (result == JFileChooser.APPROVE_OPTION) {
                    File selectedFile = fileChooser.getSelectedFile();
                    JOptionPane.showMessageDialog(Form.this, "Selected Image: " + selectedFile.getAbsolutePath());
                }
            }
        });
        add(chooseImageButton);

        add(new JLabel(""));
        imageLabel = new JLabel("Selected Image will be displayed here");
        add(imageLabel);

        submitButton = new JButton("Submit");
        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String firstName = firstNameField.getText();
                String lastName = lastNameField.getText();
                System.out.println("First Name: " + firstName);
                System.out.println("Last Name: " + lastName);
            }
        });
        add(submitButton);
        setVisible(true);
    }
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new Form();
            }
        });
    }
}