#!/usr/bin/env python
# coding:utf-8

INPUT_NAME = 'INPUT.TXT'
OUTPUT_NAME = 'OUTPUT.TXT'


def read_data(path):
    with open(path) as _:
        one_jump, length = list(map(int, _.readline().strip().split()))
    return one_jump, length


def write_result(path, result):
    with open(path, 'w') as _:
        _.write(str(result))


def graph_vars(one_jump, length, steps=0, counter=0):
    if length > steps:
        for next_step_len in range(1, one_jump + 1):
            counter = graph_vars(one_jump, length, steps=steps + next_step_len, counter=counter)
    elif length == steps:
        counter += 1
    return counter


def main():
    one_jump, length = read_data(INPUT_NAME)
    combinations = graph_vars(one_jump, length)
    write_result(OUTPUT_NAME, combinations)


if __name__ == '__main__':
    main()
