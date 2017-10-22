package view;

import controller.Controller;
import model.*;
import repository.NoProgramException;

import java.util.Scanner;

public class View {
    public View(Controller _controller) {
        this._controller = _controller;
    }

    private Controller _controller;

    private void _printMenu() {
        System.out.println("Main Menu:");
        System.out.println("\t 1. Input a program.");
        System.out.println("\t 2. Run a program.");
        System.out.println("\t 0. Exit");
    }

    public void run() {
        while (true) {
            _printMenu();
            int input = _getUserInput();
            switch (input) {
                case 1: {
                    _inputProgram();
                    break;
                }
                case 2: {
                    _runProgram();
                    break;
                }
                case 0: {
                    return;
                }
                case -1: {
                    System.out.println("Invalid input. Please try again.");
                    break;
                }
                default: {
                    System.out.println("Sorry, the option does not exist. Please try again.");
                    break;
                }
            }
        }
    }

    private int _getUserInput() {

        System.out.println("Please insert an option: ");
        Scanner scanner = new Scanner(System.in);
        String lineInput = scanner.nextLine();

        try {
            int option = Integer.parseInt(lineInput);
            if (option >= 0) {
                return option;
            }
        } catch (java.lang.NumberFormatException e) {
            System.out.println("The input was invalid. Please insert a valid option.");
        }
        return -1;
    }

    private void _printInputProgram() {
        Statement proba1 = new AssignStatement("Variabila", new ConstantExpression(32));
        Statement proba2 = new ComposedStatement(
                new AssignStatement("firstVariable", new ConstantExpression(2)),
                new PrintStatement(new VariableExpression("variableV"))
        );

        Statement proba3 = new ComposedStatement(
                new ComposedStatement(
                        new AssignStatement(
                                "var1",
                                new ArithmeticExpression(
                                        '/', new ConstantExpression(4), new ConstantExpression(0)
                                )
                        ),
                        new PrintStatement(new ConstantExpression(43))
                ),
                new PrintStatement(new VariableExpression("variableV"))
        );
        Statement proba4 = new PrintStatement(new ConstantExpression(10));

        System.out.println("Here are the program options: ");
        System.out.println("\t1. " + proba1);
        System.out.println("\t2. " + proba2);
        System.out.println("\t3. " + proba3);
        System.out.println("\t4. " + proba4);
        System.out.println("\t0. Back");

    }

    private void _inputProgram() {
        Statement rootProgram = new PrintStatement(new ConstantExpression(0));
        Statement proba1 = new AssignStatement("Variabila", new ConstantExpression(32));
        Statement proba2 = new ComposedStatement(
                new AssignStatement("firstVariable", new ConstantExpression(2)),
                new PrintStatement(new VariableExpression("variableV"))
        );

        Statement proba3 = new ComposedStatement(
                new ComposedStatement(
                        new AssignStatement(
                                "var1",
                                new ArithmeticExpression(
                                        '/', new ConstantExpression(4), new ConstantExpression(0)
                                )
                        ),
                        new PrintStatement(new ConstantExpression(43))
                ),
                new PrintStatement(new VariableExpression("variableV"))
        );
        Statement proba4 = new PrintStatement(new ConstantExpression(10));
        ExecutionStack<Statement> executionStack = new ExecutionStack<>();
        IDictionary<String, Integer> dictionary = new Dictionary<>();
        MyList<Integer> messages = new MyList<>();

        while (true) {
            _printInputProgram();
            int option = _getUserInput();
            switch (option) {
                case 1: {
                    executionStack.push(proba1);
                    break;
                }
                case 2: {
                    executionStack.push(proba2);
                    break;
                }
                case 3: {
                    executionStack.push(proba3);
                    break;
                }
                case 4: {
                    executionStack.push(proba4);
                    break;
                }
                case 0: {
                    return;
                }
                default: {
                    System.out.println("Invalid option. Please try again.");
                    break;
                }
            }
            ProgramState ps = new ProgramState(executionStack, dictionary, messages, rootProgram);
            _controller.get_repository().addProgramState(ps);
        }
    }

    private void _printRunPrograms() {
        System.out.println("Here are the options for the program running: ");
        System.out.println("\t1. One step execution");
        System.out.println("\t2. Full execution");
        System.out.println("\t0. Back");
    }

    private void _runProgram() {
        while (true) {
            _printRunPrograms();
            int input = _getUserInput();
            switch (input) {
                case 1: {
                    try {
                        _controller.executeOneStep();
                        System.out.println(_controller.getCurrentState());
                        System.out.println("\t==>");
                    } catch (DivisionByZeroException | EmptyStackException | NoProgramException | KeyNotInsertedException exception) {
                        System.out.println(exception.getMessage());
                    }
                    break;
                }
                case 2: {
                    try {
                        _controller.executeAll();
                        System.out.println(_controller.getCurrentState());
                    } catch (DivisionByZeroException | NoProgramException | EmptyStackException | KeyNotInsertedException exception) {
                        System.out.println(exception.getMessage());
                    }
                    break;
                }
                case 0: {
                    return;
                }
                case -1: {
                    System.out.println("Please insert a valid input.");
                    break;
                }
                default: {
                    System.out.println("Invalid option. Please try another one.");
                    break;
                }
            }
        }
    }
}
