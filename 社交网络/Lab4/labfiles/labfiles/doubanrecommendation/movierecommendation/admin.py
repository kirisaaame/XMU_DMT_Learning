from django.contrib import admin
from import_export import resources
from movierecommendation.models import QuestionAnswerKB,QuestionIndex
from import_export.admin import ImportExportModelAdmin

class QuestionAnswerResource(resources.ModelResource):
    class Meta:
        model = QuestionAnswerKB
        export_order = ('question','answer')

@admin.register(QuestionAnswerKB)
class MQuestionAnswerAdmin(ImportExportModelAdmin):
    list_display = ('question','answer')
    search_field = ('question')
    resource_class = QuestionAnswerResource

class IndexResource(resources.ModelResource):
    class Meta:
        model = QuestionIndex
        export_order = ('keyword', 'doclist')

@admin.register(QuestionIndex)
class QuestionIndexAdmin(ImportExportModelAdmin):
    list_display = ('keyword', 'doclist')
    search_fields = ('keyword', 'doclist')
    resource_class = IndexResource
