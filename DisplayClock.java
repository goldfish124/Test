package com.school.JAVAFX;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;

public class DisplayClock extends Application{
//	@Override
//	public void start(Stage arg0) throws Exception {
//		// TODO Auto-generated method stub
//		
//	}
	@Override  //Override the start method in the Application class
	public void start(Stage primaryStage) {
		//Create a Clock and a label
		Clockpane clock = new Clockpane();
		String timeString = clock.getHour() + "+" +clock.getMinute() + "+" + clock.getSecond();
		Label lblCurrentTime = new Label(timeString);
		
		//Place clock and label in border pane
		BorderPane pane = new BorderPane();
		pane.setCenter(clock);
		pane.setBottom(lblCurrentTime);
		BorderPane.setAlignment(lblCurrentTime, Pos.TOP_CENTER);
		
		//Create a scene and place it in the stage
		Scene scene = new Scene(pane, 250, 250);
		primaryStage.setTitle("DisplayClock");//Set the stage title
		primaryStage.setScene(scene);//Place the scene in the stage
		primaryStage.show();//Display the stage
	}
//	public static void main(String[] args) {
//		// TODO Auto-generated method stub
//
//	}

}
