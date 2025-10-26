# AddressBook

A lightweight, command-line address book application written in C for managing contacts efficiently. Store, search, edit, and organize your contacts with persistent CSV file storage.

## Features

- **Create Contacts**: Add new contacts with name, phone number, and email validation
- **Search Contacts**: Find contacts by name, phone number, or email with partial matching support
- **Edit Contacts**: Modify existing contact information
- **Delete Contacts**: Remove contacts with confirmation prompts
- **List Contacts**: View all contacts sorted by name, phone, or email
- **Persistent Storage**: Automatic saving and loading from CSV file
- **Input Validation**: 
  - Name: Alphabets and spaces only
  - Phone: 10-digit numeric validation with uniqueness check
  - Email: Basic format validation with .com domain requirement

## Project Structure

```
├── contact.h       # Main header file with structure definitions
├── contact.c       # Core functionality implementation
├── file.h          # File operations header
├── file.c          # CSV file read/write operations
├── main.c          # Main program and menu interface
├── populate.h      # Optional dummy data header
├── populate.c      # Optional dummy data for testing
└── contacts.csv    # Auto-generated contact storage file
```

## Getting Started

### Prerequisites

- GCC compiler or any C compiler
- Standard C libraries

### Compilation

Compile the project using GCC:

```bash
gcc main.c contact.c file.c populate.c -o addressbook
```

Or use the simplified command:

```bash
gcc *.c -o addressbook
```

### Running the Application

```bash
./addressbook
```

## Usage

Upon running, you'll see the main menu:

```
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit
```

### Creating a Contact

1. Select option `1`
2. Enter contact details when prompted:
   - **Name**: Letters and spaces only
   - **Phone**: Exactly 10 digits, must be unique
   - **Email**: Must end with .com

### Searching for Contacts

1. Select option `2`
2. Choose search criteria (name/phone/email)
3. Enter search term (supports partial matching)

### Editing a Contact

1. Select option `3`
2. Choose search criteria to find the contact
3. Select the contact from search results
4. Choose what to edit (name/phone/email)
5. Enter new value

### Deleting a Contact

1. Select option `4`
2. Choose search criteria to find the contact
3. Select the contact from search results
4. Type `YES` to confirm deletion

### Listing All Contacts

1. Select option `5`
2. Choose sort criteria (name/phone/email)
3. View sorted contact list

## Data Storage

Contacts are automatically saved to `contacts.csv` in the following format:

```csv
John Doe,1234567890,john@example.com
Alice Smith,0987654321,alice@example.com
```

The file is:
- Loaded automatically on program start
- Saved automatically on program exit

## Technical Details

- **Maximum Contacts**: 100 (configurable via `MAX_CONTACTS` in contact.h)
- **Data Structure**: Array-based storage with contact counter
- **Search Algorithm**: Case-insensitive substring matching
- **Sort Algorithm**: Selection sort implementation
- **Validation**: Real-time input validation with error messages

## Validation Rules

| Field | Requirements |
|-------|-------------|
| Name  | Only alphabets and spaces |
| Phone | Exactly 10 digits, numeric only, must be unique |
| Email | Must contain alphabets/special chars and end with .com |

## Contributing

Contributions are welcome! Feel free to:
- Report bugs
- Suggest new features
- Submit pull requests

## Future Enhancements

- [ ] Support for additional email domains
- [ ] International phone number formats
- [ ] Export to different file formats
- [ ] Advanced sorting (case-insensitive, multi-field)
- [ ] Backup and restore functionality

## License

This project is open source and available for educational purposes.

## Author

Krishnakant C. Pore

## Acknowledgments

- Built as a learning project for C programming
- Demonstrates file I/O, structure manipulation, and input validation

## Repository

GitHub: [https://github.com/SLADE0261/AddressBook](https://github.com/SLADE0261/AddressBook)