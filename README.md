# Fuse

Fuse is a chat system that uses Git as the main source to connect
between client and server. At first, you might confusing because it
is just a console application, but you can really chat with others.

## Compilation Steps

First, use `git clone https://github.com/antagonistry/fuse.git` to
clone the chat history. Second, run `./build.sh` to compile the
executable version of Fuse. Then chat whatever you want.

## How To Use

Fuse has a few commands that can be run through the chat, those being
`@quit`, `@q`, `@exit`, `@e`, `@help` and `@h`.
If you make a typo, you cannot change the dialogue you just entered, but
you can modify the file yourself!

## How It Works

Fuse uses Github's auto-merge pull request so that after a chat, everyone
can make a pull request and it will automatically update **if the moderator
accepts the pull request.** Sometimes the chat won't update to your newest
dialogue because of the moderator haven't review your pull request yet. You
can also fork this repository for your local community!

## Note

The maximum length of a chat is 512 lines, including the header lines.
To make it accessible for the previous chat, you should backup it for
some situation like someone spamming.

If you somehow can't compile the executable, there's just a person that
accidently delete or modify, or they just want to delete or modify the
source file.

## Support

You can support me by donating to me by this link: http://bit.ly/47gJnHU, or
support me by using it!
