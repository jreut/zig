//===-- ResourceScriptTokenList.h -------------------------------*- C++-*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===---------------------------------------------------------------------===//
//
// This is a part of llvm-rc tokens header. It lists all the possible tokens
// that might occur in a correct .rc script.
//
//===---------------------------------------------------------------------===//


// Long tokens. They might consist of more than one character.
TOKEN(Invalid)      // Invalid token. Should not occur in a valid script.
TOKEN(Int)          // Integer (decimal, octal or hexadecimal).
TOKEN(String)       // String value.
TOKEN(Identifier)   // Script identifier (resource name or type).

// Short tokens. They usually consist of exactly one character.
// The definitions are of the form SHORT_TOKEN(TokenName, TokenChar).
// TokenChar is the one-character token representation occuring in the correct
// .rc scripts.
SHORT_TOKEN(BlockBegin, '{')   // Start of the script block; can also be BEGIN.
SHORT_TOKEN(BlockEnd, '}')     // End of the block; can also be END.
SHORT_TOKEN(Comma, ',')        // Comma - resource arguments separator.
SHORT_TOKEN(Plus, '+')         // Addition operator.
SHORT_TOKEN(Minus, '-')        // Subtraction operator.
SHORT_TOKEN(Pipe, '|')         // Bitwise-OR operator.
SHORT_TOKEN(Amp, '&')          // Bitwise-AND operator.
SHORT_TOKEN(Tilde, '~')        // Bitwise-NOT operator.
SHORT_TOKEN(LeftParen, '(')    // Left parenthesis in the script expressions.
SHORT_TOKEN(RightParen, ')')   // Right parenthesis.