# `Digit_DP`
Refer to `Digit_DP.cpp`.

A generic digit DP framework based on a user-defined finite state machine.

The framework automatically handles

- tight constraint
- leading zeros
- digit position (string index)

so these **must not** be included in the user-defined state.

The user only needs to define the state transition and the final evaluation.

## Template

```cpp
template<
    size_t NUM_STATE,
    typename OUTPUT_TYPE,
    array<int, NUM_STATE> (*e)(),
    array<int, NUM_STATE> (*next_state)(
        array<int, NUM_STATE> now_state,
        int prev_lz,
        int next_lz,
        int digit
    ),
    OUTPUT_TYPE (*cal_state)(array<int, NUM_STATE> leaf_state),
    int maxdigit = 9
>
```

## Constructor

```cpp
Digit_DP(state_type EACH_STATE_MAX_SZ, int NUM_LENGTH)
```

### Parameters

- `EACH_STATE_MAX_SZ`
    - An `array<int, NUM_STATE>` describing the number of possible values for each state dimension.
    - For example:
        - modulo 3 state → `3`
        - binary state → `2`
        - decimal digit → `10`

- `NUM_LENGTH`
    - Maximum length of the input number.
    - The length should match the digit system specified by `maxdigit`.
    - For example:
        - decimal → maximum decimal length
        - binary (`maxdigit = 2`) → maximum binary string length

## State

The DP state is defined as

```cpp
using state_type = array<int, NUM_STATE>;
```

The computation starts from

```cpp
state_type e();
```

which returns the initial state.

## State Transition

```cpp
state_type next_state(
    state_type now_state,
    int prev_lz,
    int next_lz,
    int digit
);
```

This function defines how the state changes after reading one digit.

Parameters:

- `now_state` : current state
- `prev_lz` : whether the previous prefix consists entirely of leading zeros
- `next_lz` : whether the new prefix is still all leading zeros after appending this digit
- `digit` : current digit

Only the user-defined state should be updated here.

The framework automatically maintains

- tight
- leading zero
- digit position

so they should **not** be stored inside `state_type`.

## Final Evaluation

```cpp
OUTPUT_TYPE cal_state(state_type leaf_state);
```

After all digits have been processed, this function is called on the final state to determine the contribution of that number.

## Digit Base

```cpp
maxdigit
```

The maximum digit value.

Default:

```cpp
maxdigit = 9
```

Examples:

| Number System | `maxdigit` |
|---------------|-----------:|
| Decimal | `9` |
| Binary | `2` |
| Octal | `7` |
| Hexadecimal | `15` |

## Complexity

Currently, no state pruning is implemented.

In the worst case, the framework enumerates

```
(all user states)
× 2 (tight)
× 2 (leading zero)
× NUM_LENGTH
```

states.

## Member Functions

### `run`

```cpp
OUTPUT_TYPE run(string num);
```

Returns the DP result for the inclusive range

```
[0, num]
```

The input string should use the digit system corresponding to `maxdigit`.

### `debug`

```cpp
void debug();
```

Prints the state and the corresponding output for every number in

```
0 ~ 10
```

and

```
0 ~ 100
```

This is mainly intended for verifying state transitions and debugging the state machine.
