# OLA-Doc: Doctor Management System

OLA-Doc is a C++ terminal-based system for managing doctor appointments, patient records, and administrative tasks.

## Features

- **User Roles**: Admin, Doctor, Patient.
- **Functionalities**:
  - Admin: Add/update doctors, view users.
  - Doctor: Display appointments, profiles.
  - Patient: Book appointments, give feedback, make payments (not fully implemented).

## Usage

1. **Execution**:
   - Compile and run the C++ source code to start the program.
  
2. **User Login**:
   - Choose user type: Admin, Doctor, or Patient.
   - Signup option available.

3. **Functionality Access**:
   - Each user type accesses specific functionalities based on roles.

## File Structure

- **Main File**: `main.cpp`
- **Classes**: `user.h`, `Patient.h`, `Doctor.h`, `Admin.h`, `olaDoc.h`, `Feedback.h`.

## Contributing

Contributions for enhancements, new features, or bug fixes are welcome via pull requests or issue submissions.

**Note**: The payment functionality is yet to be implemented fully.
