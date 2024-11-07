/*
6. Using ObjectInputStream and ObjectOutputSteam write some value to the file than read from the file convert to string and display on the monitor
*/

import java.io.*;

class Person implements Serializable {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}

public class main6 {

    public static void main(String[] args) {
        try {
            // Writing an object to the file
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(new FileOutputStream("person.dat"));

            // Taking input from the user to create a Person object
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter name: ");
            String name = reader.readLine();
            System.out.print("Enter age: ");
            int age = Integer.parseInt(reader.readLine());

            Person person = new Person(name, age);

            objectOutputStream.writeObject(person);
            System.out.println("Person object has been written to person.dat");

            objectOutputStream.close();

            // Reading an object from the file
            ObjectInputStream objectInputStream = new ObjectInputStream(new FileInputStream("person.dat"));
            Person readPerson = (Person) objectInputStream.readObject();

            // Displaying the object on the monitor
            System.out.println("\nReading and Displaying Person Object:");
            System.out.println(readPerson);

            objectInputStream.close();

        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
