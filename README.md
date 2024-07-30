# My_sokoban

This program recreate the sokoban game in a terminal using the library `ncurses`.

<div align=center>
<img src="asset/Sokoban.gif">
</div>

## Game goal

Replaces all **boxes** on their **locations** in the warehouse (map).

If all boxes are on their locations, you **win** !

But, if there are no boxes moves available (boxes stuck in corners for instance), you **lose** !

**_Warning, Due to a flaw in the code, if no movement is possible with at least one box stuck next to another stuck box, the game will never end._**

## How to launch the game ?

**Download** the project, make sure you have the `ncurses` library installed. If it is not installed, **install it** with this command for **Fedora** ([commands for other Linux distributions](https://www.cyberciti.biz/faq/linux-install-ncurses-library-headers-on-debian-ubuntu-centos-fedora/)):

```bash
sudo dnf install ncurses-devel
```

Now, you can place yourself at the **root of the project** and execute in a **terminal** these commands:

```bash
make
./my_sokoban maps/map
```

**Warning**, `my_sokoban` executable take one setting: the game map, findable in the folder `maps`.

You can create yourself your map, using these **rules**:

- There must be the **same number** of boxes and boxes' locations.
- There must be **only one player**, so one 'P' in all map.
- There must not be **any holes** in walls around the map.
- You must use only **spaces**, **'#'**, **'O'** and **'P'**.

## How to play ?

As soon as the game is launched, you can **move the player** with **arrows keys**.

You can also **reset the game** using **spacebar**.

If you need to **stop playing**, you can press **escape** to quit the game.
