#include<stdio.h>

#define MAX 12

struct team{
   char teamName[50];
   int matchesPlayed;
   int wins;
   int draws;
   int losses;
   int g_scored;
   int g_con;
   int g_diff;
   int points;
};

struct team teams[MAX];

void addteam(){
  int i, j;
  int highestPoints=0, highestDiff=0, lowestPoints=0;
  int pointCount=0;
  int n;
  int totalGoals=0;
  float totalAvg;
   struct team temp;

  printf("\n--------------------------------------------------\n");
  printf("NATIONAL FOOTBALL TOURNAMENT MANAGEMENT SYSTEM\n");
  printf("----------------------------------------------------\n");

  printf("Enter number of teams(MAX 12):");
  scanf("%d",&n);
  for(i=0; i<n; i++){
    printf("Team %d\n", i+1);
    printf("Enter Team Name:");
    scanf("%s",teams[i].teamName);

    printf("Matches Played: ");
    scanf("%d",&teams[i].matchesPlayed);

    printf("Wins:");
    scanf("%d", &teams[i].wins);

    printf("Draws:");
    scanf("%d", &teams[i].draws);

    printf("Losses:");
    scanf("%d", &teams[i].losses);

    printf("Goals Scored:");
    scanf("%d",& teams[i].g_scored);

    printf("Goals Conceded:");
    scanf("%d",&teams[i].g_con);

   teams[i].g_diff=teams[i].g_scored-teams[i].g_con;
  teams[i].points=teams[i].wins*3+teams[i].draws*1;
  totalGoals+=teams[i].g_scored;



}

for(i=1; i<n; i++){
    if(teams[i].points>teams[highestPoints].points){
        highestPoints=i;
    }
    if(teams[i].g_diff>teams[highestDiff].g_diff){
        highestDiff=i;
    }
    if(teams[i].points<teams[lowestPoints].points){
        lowestPoints=i;
    }
}

for(i=1; i<n-1; i++){
    for(j=0; j<n-i-1; j++){
        if(teams[j].points<teams[j+1].points|| (teams[j].points==teams[j+1].points && teams[j].g_diff<teams[j+1].g_diff) || (teams[j].points==teams[j+1].points && teams[j].g_diff==teams[j+1].g_diff && teams[j].g_scored<teams[j+1].g_scored)){
           temp=teams[j];
           teams[j]=teams[j+1];
           teams[j+1]=temp;
          }

       }
    }

 totalAvg=(float)totalGoals/n;
 printf("\n--------Specified Teams---------\n");
 printf("Highest Points: %s-%d points\n",teams[highestPoints].teamName, teams[highestPoints].points);
 printf("Highest Goal Difference: %s-%d\n",teams[highestDiff].teamName, teams[highestDiff].g_diff);
 printf("Lowest Points: %s-%d pionts", teams[lowestPoints].teamName, teams[lowestPoints].points);

   printf("\n------------------FINAL TOURNAMENT TABLE--------------------\n");
   printf("%-5s %-20s %-5s %-5s %-5s %-5s %-5s %-5s %-5s\n", "Pst", "T_Name", "MP", "W", "D", "L", "GS", "GD", "Pt");
 for(i=0; i<n; i++){
    printf("%-5d %-20s %-5d %-5d %-5d %-5d %-5d %-5d %-5d\n",i+1, teams[i].teamName, teams[i].matchesPlayed, teams[i].wins, teams[i].draws, teams[i].losses, teams[i].g_scored,teams[i].g_diff, teams[i].points);
}

printf("---------------------TOURNAMENT ANALYSIS----------------------\n");
    // Champion
    printf("1, Champion:");
    printf("%s---%d points---%d goals", teams[0].teamName, teams[0].points, teams[0].g_scored);

    // TOP TEAMS
    printf("\n-----------TOP 3 TEAMS-----------\n");
    printf("%s %-20s %-5s %-5s\n", "Pst", "T_Name", "GS", "Pts");
    for(i=0; i<3; i++){
        printf("%d %-20s %-5d %-5d\n",i+1, teams[i].teamName, teams[i].g_scored, teams[i].points);
    }

    // BOTTOM 3 TEAMS
    printf("----------BOTTOM 3 TEAMS----------\n");
    for(i=n-3; i<n; i++){
        printf("%-5d %-15s %-5d %-5d\n",i, teams[i].teamName, teams[i].g_scored, teams[i].points);
    }
    // TOATAL FOALS SCORED
    printf("-----------------------------------------------------\n");
    printf("Total Goals Scored= %d\n", totalGoals);
    printf("Average Goals Scored per Team= %.1f",totalAvg);
  }

int main()
{
    addteam();
}
