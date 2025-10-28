#ifndef EXIT_CODES_H
#define EXIT_CODES_H

enum ExitCode {
    Success = 0,           ///< Program completed successfully
    UsageError = 1,        ///< Incorrect usage (wrong number of arguments)
    UnknownGame = 2,       ///< Game name not recognize
    InvalidPlayers = 3,    ///< Wrong number of players for a given game
    GameCreationError = 4, ///< Could not create game object
    RuntimeError = 5,      ///< Exceptions during gameplay 
};

#endif // EXIT_CODES_H
