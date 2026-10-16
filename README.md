# Real Estate Listing Manager

> C program to browse, search, sort and export property listings.

## Overview

- Lets users browse, search and rank a real-estate dataset by different criteria.

## Data / Scope

- Listings with location, city, price, rooms, bathrooms, carpark, type and furnishing, loaded from a CSV file.

## Workflow

- Loaded CSV rows into an array of structured records.
- Offered a menu to display rows and search or filter by any single column.
- Sorted by any column, ascending or descending, with hand-written algorithms, then exported to CSV.

## Results

- Complete menu-driven tool: display, search, sort, export.
- Sorting works on every column in both directions.
- Practiced CSV parsing and input validation in C.

## Tech Stack

C, CSV file I/O, Sorting algorithms, Input validation

## Repository Structure

```
real_estate_listing.c   Console program: display, search, sort and export property listings
```

## How to Run

```bash
gcc real_estate_listing.c -o listing
./listing
```
The program reads a CSV named `file.csv` in the same folder with columns Location, City, Price, Rooms, Bathroom, CarPark, Type, Furnish (up to 3,940 rows).

## Team

Individual project (programming course case study).

## Notes

- The listings CSV is not included; use any dataset with the columns above.

## Author

Nadya Angelie Lislie, BINUS University (Computer Science and Statistics). [LinkedIn](https://www.linkedin.com/in/nadya-angelie-lislie/) | [GitHub](https://github.com/Nadya-AngelieLislie)

## Continuous Integration

GitHub Actions (`.github/workflows/ci.yml`) runs `ruff` and `pytest` repository-health checks on every push; run them locally with `make lint test`.
