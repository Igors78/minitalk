# Mini Talk

## Getting Started

- This program can serve only for learning purposes
- Program client transmits string to program server using SIGUSR1 and SIGUSR2

A signal is guaranteed to be delivered, in the sense that if a process successfully calls kill, then the target will receive the signal. This is asynchronous: the sender has no way to know when the signal is received or processed. However, this does not guarantee that the signal will be delivered. The target could die before it can process the signal. If the target is ignoring the signal at the time it is delivered, the signal will have no effect. If the target receives multiple instances of the same signal number before it can process them, the signals may (and usually are) merged: if you send the same signal twice to a process, you can't know whether the process will receive the signal once or twice. Signals are mostly designed to kill a process or as a way to make a process pay attention, they aren't designed for communication as such.

If you need reliable delivery then you need a different communication mechanism. There are two main communication mechanisms between processes: a pipe allows unidirectional communication; a socket allows bidirectional communication and multiple connections to the same server. If you need the target to process as many notifications as you send it, send bytes over a pipe.
/FROM LINUX STACK EXCHANGE/

## Setup

- Run `make` in cloned repository
- Run `./server`
- Server PID will be displayed
- Don't interrupt server, let it run

## Usage

- Run client in separate terminal window in following format `./client <SERVER PID> <STRING TO TRANSMIT>`
- Look for your string in server window
- When finished `kill -9 <SERVER PID>` or CTRL^C in server terminal

## More info on this project in subject.pdf

## Test strings examples in test.txt

## Built with love and

- C

## Author

👤 **Igors Oleinikovs**

- GitHub: [Igors78](https://github.com/Igors78)
- Twitter: [@oleinikovs](https://twitter.com/oleinikovs)
- LinkedIn: [Oleinikovs Igors](https://www.linkedin.com/in/igors-oleinikovs-17a10958/)

## 🤝 Contributing

Contributions, issues, and feature requests are welcome!

## Show your support

Give a ⭐️ if you like this project!

## Acknowledgments

- 42 Wolfsburg
- CodeVault: [Code Vault](https://www.youtube.com/watch?v=jF-1eFhyz1U&t=18s)
- T.Khirianov: [YT](https://www.youtube.com/channel/UCQfwKTJdCmiA6cXAY0PNRJw)

## 📝 License

This project is [UNLicense](./LICENSE) licensed.
