# Первым аргументом процедуры message может стоять тип сообщения

message("Regular message")

message(STATUS "A status Message")

message(WARNING "A warning")

message(SEND_ERROR "Print an error")

# После сообщения типа FATAL_ERROR cmake автоматически завершает работу
message(FATAL_ERROR "Print an error and quit")

message("This message won't print")


