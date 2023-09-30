#include <iostream>
#include <string>

using namespace std;

struct Student 
{
    string name;
    int id;
    double assignmentScore1;
    double assignmentScore2;
    double quizScore;
    double examScoreMaths;
    double examScoreEnglish;
    double examScoreIT;
    double examScoreScience;
    double overallScore;
    char letterGrade;
    string feedback;
};

const double ASSIGNMENT_WEIGHT = 0.3;
const double QUIZ_WEIGHT = 0.3;
const double EXAM_WEIGHT = 0.4;

char calculateLetterGrade(double score) 
{
    if (score >= 80)
        return 'A';
    else if (score >= 60)
        return 'B';
    else if (score >= 50)
        return 'C';    
    else
        return 'F';
}

void provideFeedback(Student& student) 
{
    if (student.overallScore >= 80)
        student.feedback = "Congratulations on an excellent performance!";
    else if (student.overallScore >= 60)
        student.feedback = "Good job, but there's room for improvement.";
    else
        student.feedback = "You may want to seek help or study harder.";
}

int main() 
{
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int studentCount = 0;

	cout<<"\t\t\tSTUDENT GRADE CALCULATOR\n";

    while (studentCount < MAX_STUDENTS) 
	{
        Student student;
        cout << "\nEnter student name (or 'exit' to quit): ";
        cin >> student.name;

        if (student.name == "exit") 
		{
            break;
        }

        cout << "Enter student ID: ";
        cin >> student.id;

		cout<<"\t\t\tScore of Assignments \n\n";
		
        cout << "Enter First Assignment Marks (0-50): ";
        cin >> student.assignmentScore1;
        
        cout << "Enter Second Assignment Marks (0-50): ";
        cin >> student.assignmentScore2;

		cout<<"\n\n\t\t\tScore of Quiz  \n\n";

        cout << "Enter quiz score (0-100): ";
        cin >> student.quizScore;

		cout<<"\n\n\t\t\tScore of Examination \n\n";

        cout << "Enter Mathematics Exam Marks (0-25): ";
        cin >> student.examScoreMaths;
        
        cout << "Enter English Exam Marks (0-25): ";
        cin >> student.examScoreEnglish;
        
        cout << "Enter Science Exam Marks (0-25): ";
        cin >> student.examScoreScience;
        
        cout << "Enter Information Technology Exam Marks (0-25): ";
        cin >> student.examScoreIT;

        // Calculate the overall score and letter grade
        student.overallScore = ((student.assignmentScore1+student.assignmentScore2) * ASSIGNMENT_WEIGHT +
                                student.quizScore * QUIZ_WEIGHT +
                                (student.examScoreMaths+student.examScoreEnglish+student.examScoreScience+student.examScoreIT) * EXAM_WEIGHT);

        student.letterGrade = calculateLetterGrade(student.overallScore);

        // Provide feedback based on the letter grade
        provideFeedback(student);

        students[studentCount] = student;
        studentCount++;
    }

    // Display the results
    cout << "\n--- Student Grades ---\n\n";
    for (int i = 0; i < studentCount; ++i) 
	{
        const Student& student = students[i];
        cout<<"Student "<<i+1<<" Result\n";
        cout << "Student Name: " << student.name << "\tStudent ID: " << student.id << endl;
        cout << "Overall Score: " << student.overallScore << endl;
        cout << "Letter Grade: " << student.letterGrade << endl;
        cout << "Feedback: " << student.feedback << endl << endl;
    }

    return 0;
}

