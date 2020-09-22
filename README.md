# DNA Analyzer System

## A DNA Sequence Analyzer App Goal
The goal of the system is to load, analyze, manipulate and save DNA sequences.

## Description

DNA sequences are composed of four types of nucleotides; the nucleotides are marked A (Adenine), G (Guanine), C (Cytosine) and T (Thymine). A full DNA molecule usually consists of two strands, connected to each other in base-pair connections: As with Ts, and Cs with Gs. Three successive nucleotides generate a codon, which might be chemically "read" in various ways.

The system will interact with the user through a CLI (Command Line Interface) that uses the standard I/O. Using that interface, the user will be able to load DNA sequences from files, to analyze them, to manipulate them (e.g., by extracting sequence slices or by modifying the sequence), and to store modified sequences and reports.

## Common Usage of the DNA Analyzer
### Source Sequences
The DNA Analyzer application will help our scientists in their genetic and biologicalresearch. For example, a common usage might be to hold 10--20 human DNAsequences (single- or double-strand), and have the research on them.Each such a sequence is about 1.510^9 nucleotides long for the single strand, or 310​9nucleotides long for the double strand.

### Analyzed Slices
The research itself might include thousands of slices from those human DNA genomesequences, that might vary in length - from a few dozens of nucleotides to millions ofthem.

### Short Sequences
We might also hold lots of short DNA sequences (from a few nucleotides to severalhundreds of them), that will later be used in DNA manipulation and analysis.

### Analysis Types
There might be a few typical types of analyses that researchers might like to have onthose slices. Some of the most common analyses and manipulations are:

Mutations -> Changing the original DNA slice by replacing a few nucleotides by others. Forexample, taking a slice and replacing 10 random nucleotides in it with ‘G’. Then, wecan compare a few such mutated sequences by various means - e.g., finding therelevant codons that generate specific protein types.

Injections -> Creating a new sequence from an existing slice that another short sequence was“injected” into it at a given location. We might hold thousands of such “shortsequences” (from a few nucleotides to hundreds or so) and create many differentinjections (e.g., creating 20 new slices by “injecting” the sequence “AACTGAAGCT”into a given slice in 20 different locations).
