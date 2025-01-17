import javafx.application.*;
import javafx.event.*;
import javafx.geometry.*;
import javafx.scene.*;
import javafx.scene.canvas.*;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.scene.paint.*;
import javafx.stage.*;

public class RadioButtonDemo extends Application {
    GraphicsContext gc;
    String st = "";

    public static void main(String[] args) {
        // Start the JavaFX application by calling launch().
        launch(args);
    }

    // Override the start() method.
    public void start(Stage myStage) {
        // Give the stage a title.
        myStage.setTitle("Draw Shapes");
        // Use a FlowPane for the root node. In this case,
        // vertical and horizontal gaps of 10.
        FlowPane rootNode = new FlowPane(10, 10);
        // Center the controls in the scene.
        rootNode.setAlignment(Pos.CENTER);
        // Create a scene.
        Scene myScene = new Scene(rootNode, 300, 600);
        // Set the scene on the stage.
        myStage.setScene(myScene);
        final Canvas canvas = new Canvas(300, 500);
        gc = canvas.getGraphicsContext2D();

        // Create the radio buttons.
        RadioButton rbc = new RadioButton("circle");
        RadioButton rbr = new RadioButton("rectangle");
        RadioButton rbl = new RadioButton("line");
        // Create a toggle group.
        ToggleGroup tg = new ToggleGroup();
        // Add each button to a toggle group.
        rbc.setToggleGroup(tg);
        rbr.setToggleGroup(tg);
        rbl.setToggleGroup(tg);
        // Handle action events for the radio buttons.
        rbc.setOnAction(new MyHandler());
        rbr.setOnAction(new MyHandler());
        rbl.setOnAction(new MyHandler());
        // Fire the event
        rbr.fire();
        // Add the label and buttons to the scene graph.
        rootNode.getChildren().addAll(rbc, rbr, rbl, canvas);
        // Show the stage and its scene.
        myStage.show();
        canvas.addEventFilter(MouseEvent.ANY, new EventHandler<MouseEvent>() {
            double x, y, x1, y1;

            public void handle(MouseEvent mouseEvent) {
                if (mouseEvent.getEventType() == MouseEvent.MOUSE_CLICKED) {

                    x = mouseEvent.getX();
                    y = mouseEvent.getY();
                }
                if (mouseEvent.getEventType() == MouseEvent.MOUSE_DRAGGED) {
                    x1 = mouseEvent.getX();
                    y1 = mouseEvent.getY();

                    gc.setFill(Color.WHITE);
                    gc.fillRect(0, 0, 300, 500);

                    if ("line".equals(st)) {

                        gc.strokeLine(x, y, x1, y1);
                        gc.strokeText("line drawn", 25, 450);
                    } else if ("rectangle".equals(st)) {
                        gc.strokeRect(x, y, x1 - x, y1 - y);
                        gc.strokeText("Area of rectangle=" + (x1 - x) * (y1 - y), 25, 450);
                    } else {
                        gc.strokeOval(x, y, x1 - x, x1 - x);
                        gc.strokeText("Area of circle=" + 3.14 * (x1 - x) * (x1 - x) / (37.8 * 37.8), 25, 450);
                    }
                }
            }
        });
    }

    class MyHandler implements EventHandler<ActionEvent> {
        public void handle(ActionEvent ae) {
            st = ((RadioButton) ae.getSource()).getText();

        }
    }
}