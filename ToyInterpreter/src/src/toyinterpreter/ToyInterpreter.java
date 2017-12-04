/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package toyinterpreter;

import controller.Controller;
import model.expressions.GreaterThanExpression;
import model.statement.WhileStatement;
import repository.ProgramStateRepository;
import view.View;

/**
 *
 * @author fovas
 */
public class ToyInterpreter {

    public static void main(String[] args) {
        // Initiate the Repository
        ProgramStateRepository repository = new ProgramStateRepository("a.log");
        // Create the controller
        Controller controller = new Controller(repository);
        // Create the view
        View mainView = new View(controller);
        // Run the main program
        mainView.run();

    }

}
