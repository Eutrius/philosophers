# 🍝 Philosophers

#### ✅ [125/125]

This project implements the dining philosophers problem, a classic computer science problem that illustrates synchronization issues and techniques in concurrent programming. The project includes both a standard implementation using mutexes (`philo`) and a bonus implementation using semaphores (`philo_bonus`).

## 📋 Table of Contents

- [Problem Description](#problem-description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Implementation Details](#implementation-details)
- [Concepts](#concepts)
- [Contributing](#contributing)

## 🤔 Problem Description

Imagine several philosophers sitting at a round table with a bowl of spaghetti in the center. There are as many forks as philosophers, and each philosopher needs two forks to eat. The philosophers alternate between eating, thinking, and sleeping - but if they don't eat for too long, they die of starvation.

The challenge is to design a solution where:

- Philosophers don't starve
- No deadlocks occur
- No race conditions happen

## ✨ Features

- Two different implementations:
  - **Standard version**: Using threads and mutexes
  - **Bonus version**: Using processes and semaphores
- Configurable parameters:
  - Number of philosophers
  - Time to die (in milliseconds)
  - Time to eat (in milliseconds)
  - Time to sleep (in milliseconds)
  - Optional: Number of times each philosopher must eat

## 🛠️ Installation

```bash
# Clone the repository
git clone <https://github.com/Eutrius/philosophers.git>

# Build the standard version
cd philo
make

# Build the bonus version
cd ../philo_bonus
make
```

## 🚀 Usage

### Standard Version

```bash
./philo num_philosophers time_to_die time_to_eat time_to_sleep [num_times_must_eat]
```

### Bonus Version

```bash
./philo_bonus num_philosophers time_to_die time_to_eat time_to_sleep [num_times_must_eat]
```

### Parameters

- `num_philosophers`: Number of philosophers at the table
- `time_to_die`: Time in milliseconds after which a philosopher dies if they haven't started eating
- `time_to_eat`: Time in milliseconds it takes for a philosopher to eat
- `time_to_sleep`: Time in milliseconds a philosopher spends sleeping
- `num_times_must_eat` (optional): Number of times each philosopher must eat before the simulation stops

### Example

```bash
./philo 5 800 200 200 5
```

This will start a simulation with:

- 5 philosophers
- A philosopher dies if they don't start eating within 800ms of their last meal
- It takes 200ms to eat
- It takes 200ms to sleep
- The simulation stops when each philosopher has eaten 5 times

## 💡 Implementation Details

### Standard Version (Mutexes)

- Each philosopher is a thread
- Each fork is protected by a mutex
- A philosopher must acquire two mutexes (forks) to eat
- Even-numbered philosophers try to take their right fork first, odd-numbered try left first (deadlock prevention)

### Bonus Version (Semaphores)

- Each philosopher is a process
- Forks are represented by a semaphore
- A monitoring process checks if philosophers died
- Uses named semaphores for synchronization

## 🧠 Concepts

This project demonstrates several important concepts in concurrent programming:

- **Thread synchronization**: Using mutexes to prevent race conditions
- **Inter-process communication**: Using semaphores in the bonus version
- **Deadlock prevention**: Implementing strategies to avoid deadlocks
- **Resource allocation**: Managing shared resources (forks)
- **Timing and scheduling**: Ensuring philosophers eat, sleep, and think in the correct sequence

## License

This project is part of the 42 curriculum and follows its academic policies.
