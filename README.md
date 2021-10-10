# Cyclocommandeur
System for using a bicycle as a controller in a game.

# Cyclocontroller

Setting up and operating a Cyclocommandeur.

**Warning!** If you have already uploaded the code once/if the cyclocommandeur was provided to you by an operator, you do not need to perform the [Code](#code) step!

## General operation

The remote control is a controller for playing car games, especially [Horizon Chase Turbo](https://store.steampowered.com/app/389140/Horizon_Chase_Turbo/).

The mapping of the controls is done as follows:

| On the bike            | Player 1 | Player 2    | Effect        |
|------------------------|----------|-------------|---------------|
| Pedal                  | W        | Up arrow    | Accelerate    |
| Left handlebar button  | A        | Left arrow  | Turn left     |
| Right handlebar button | D        | Right arrow | Turn right    |
| (soon) Brakes          | S        | Down arrow  | Brake/Reverse |
| (soon) Special button  | Space    | Right Ctrl  | Use nitro     |

## Assembly

1) Insert the bike stand, unfold it, and insert the rear wheel of the bike into it.

2) Use the rack and pinion clamps to secure the front wheel to the bike frame.

3) Test that everything is stable by getting on the bike and pedalling hard.

4) If everything is stable, put the buttons on the handlebars, and run the cables to the rear support following the brake cable. Use electrician's tape to stabilise the buttons and cables.

5) Make the cable connections using the following table:

| Wire                                         | Goes on           |
|----------------------------------------------|-------------------|
| VCC board                                    | Create a VCC line |
| GND board                                    | Create a GND line |
| Left button (one of the two wires)           | GND line          |
| Left button (the other wire)                 | Digital 4         |
| Right button (one of the two wires)          | GND line          |
| Right button (the other wire)                | Digital 5         |
| Wheel sensor, red wire                       | VCC line          |
| Wheel sensor, black wire                     | GND line          |
| Wheel sensor, one of the two remaining wires | Digital 2         |
| Wheel sensor, remaining wire                 | Digital 3         |

6) Plug the board's USB cable into a computer, start the game, and test that everything works!

## Code

Please refer to the [Cyclocommandeur main code README](./main/README.md).

**Reminder!** You can skip this step if you are an end user of the cyclocommandeur

## Troubleshooting

tbd.
