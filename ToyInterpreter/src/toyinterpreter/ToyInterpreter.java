/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package toyinterpreter;

import controller.Controller;
import model.*;
import repository.ProgramStateRepository;
import view.View;

/**
 *
 * @author fovas
 */
public class ToyInterpreter {

    public static void main(String[] args) {
        // Initialization
        ExecutionStack<Statement> executionStack = new ExecutionStack<>();
        Dictionary<String, Integer> dictionary = new Dictionary<>();
        MyList<Integer> messages = new MyList<>();

        // Initiate the Repository
        ProgramStateRepository repository = new ProgramStateRepository();

        // Create the controller
        Controller controller = new Controller(repository);
        // Create the view
        View mainView = new View(controller);
        // Run the main program
        mainView.run();

    }

}
